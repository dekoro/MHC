#include "EnemyInoshishi.h"
#include "Enemy.h"
#include "Player.h"

#define GROUP_MAX 10	 //グループの最大数
#define GROUP_COUNT_MAX 5	//グループの中の敵の最大

static enum STATE
{
	STATE_STOP,	//通常にとまってる
	STATE_WAIT,	//プレイヤを見つけて準備
	STATE_MOVE,	//移動中
};

EnemyInoshishi* GetElder(int groupNum, vector<Enemy*> enemyList)
{
	int end = enemyList.end() - enemyList.begin();
	for (int i = 0; i < end; i++)
	{
		if (//typeid(enemyList[i]) == typeid(EnemyInoshishi) &&
			enemyList[i]->GetAssetName() == imageAsset_Enemy_Ghost &&
			dynamic_cast<EnemyInoshishi*>(enemyList[i])->GetGroupNum() == groupNum &&
			dynamic_cast<EnemyInoshishi*>(enemyList[i])->IsElder() == TRUE)
		{
			return dynamic_cast<EnemyInoshishi*>(enemyList[i]);
		}
	}
	return NULL;
}


int GetSpaceGroupNum(vector<Enemy*> enemyList)
{
	int end = enemyList.end() - enemyList.begin();
	for (int i = 0; i < GROUP_MAX; i++)
	{
		int count = 0;
		count = GetGroupCount(i, enemyList);
		if ((count >= 0) && (count < GROUP_COUNT_MAX))
			return i;
	}

	return -1;
}

int GetGroupCount(int groupNum, vector<Enemy*>enemyList)
{
	if (groupNum < 0)return -1;

	int end = enemyList.end() - enemyList.begin();
	int count = 0;
	for (int j = 0; j < end; j++)
	{
		if ((enemyList[j]->GetAssetName() == imageAsset_Enemy_Ghost) &&
			(dynamic_cast<EnemyInoshishi*>(enemyList[j])->GetGroupNum() == groupNum))
		{
			count++;
		}
	}

	return count;
}

EnemyInoshishi::EnemyInoshishi(vector<Enemy*> *enemyList) :Enemy(enemyList, imageAsset_Enemy_Ghost)
{
	angle = 0.0f;
	//Vec2 pos = Vec2::Setup(Window::WIDTH / 2, Window::HEIGHT / 2);
	Vec2 pos = Vec2::Setup(GetRand(Window::WIDTH), GetRand(Window::HEIGHT));


	group = GetSpaceGroupNum(*enemyList);
	//printfDx("%d", group);

	if (group < 0)
	{
		enemyList->pop_back();
	}

	
	elder = GetElder(group, *enemyList);
	isElder = (elder == NULL);
	float range = isElder ? 50 : 20;
	CharacterInformation prm = CharacterInformation::Setup(3, 0, 1, 30, 0.05f, range);



	SetupData(pos, prm);
	Initialize();
	speed = Vec2();
}

EnemyInoshishi::~EnemyInoshishi()
{
}

void EnemyInoshishi::Initialize()
{
	isInvincible = false;
	target = NULL;
	moveCount = 0;
	stopCount = 0;
	state = STATE_STOP;
	SetMoveCount();
	SetAngle();
}

void EnemyInoshishi::Draw()
{
	if (state == STATE_WAIT && stopCount % 3 == 0 && !isDead)return;

	int posX = position.GetIntX();
	int posY = position.GetIntY();
	//float deg = angle * 180.0f / 3.14;
	static int color[GROUP_MAX][3] =
	{
		//{ 0, 0, 0 }, { 0, 0, 255 }, { 0, 255, 255 },
		//{ 0, 255, 0 }, { 255, 255, 0 }, { 255, 255, 255 },
		{ 255, 0, 255 }, { 255, 0, 0 }, { 127, 127, 127 },
		{ 127, 127, 0 }
	};
	if (isElder != TRUE)//SetDrawBright(255, 0, 0);
		SetDrawBright(color[group][0], color[group][1], color[group][2]);

	float rate = isElder ? 5.0f / 2.0f : 1.0f;

	
	device->Image()->DrawExtend(imageData->GetImageHandle(), posX, posY, 0.0f, rate);
	//DrawCircle(posX, posY, 100, GetColor(255, 255, 255), FALSE);
	SetDrawBright(255, 255, 255);
}

void EnemyInoshishi::Update()
{
	Enemy::Update();
	if (isDead)return;
	switch (state)
	{
	case STATE_STOP:	//通常に止まってる
	case STATE_WAIT:Stop(); break;	//プレイヤを見つけて止まってる
	case STATE_MOVE:Move(); break;
	default:assert(!"予期せぬステートです");
	}
}

void EnemyInoshishi::SetStopCount(int min, int max)
{
	stopCount = GetRand(max - min) + min;
}

void EnemyInoshishi::SetMoveCount()
{
	moveCount = rand() % 30 + 30;
	maxMoveCount = moveCount;
}

void EnemyInoshishi::Stop()
{
	stopCount--;

	if (target == NULL && state != 1)
	{
		CheckTargetPlayer();
		if (target != NULL)
		{
			SetStopCount(30, 30);
			SetSpeedToPlayer();
			state = STATE_WAIT;
			return;
		}
	}
	if (stopCount > 0)return;
	SetMoveCount();
	state = STATE_MOVE;
	if (target != NULL)
	{
		return;
	}
	SetAngle();
	SetSpeed();
}

void EnemyInoshishi::SetAngle()
{
	float degree = rand() % 360;
	angle = 3.14f / 180.0f * degree;
}

void EnemyInoshishi::SetSpeedToElder()
{
	if (!OutOfElderRange(100))return;
	Vec2 toElder = elder->GetPosition() - GetPosition();
	toElder.NormalizeSelf();
	toElder *= 2.0f;

	speed = toElder;
}

BOOL EnemyInoshishi::IsElder()
{
	return isElder;
}

BOOL EnemyInoshishi::OutOfElderRange(float range)
{
	if (elder == NULL)return FALSE;
	if (target != NULL)return FALSE;
	if (this->position.Distance(elder->position) < range)return FALSE;

	return TRUE;
}

void EnemyInoshishi::Move()
{
	moveCount--;
	float degree = (float)((float)moveCount / maxMoveCount) * (180.0f);
	float radian = degree * 3.14f / 180.0f;
	float rate = sin(radian);
	position += (speed * rate);

	float range = 32 / 2.0f;
	position.X = std::fminf(position.X, Window::WIDTH - range);
	position.X = std::fmaxf(0.0f + range, position.X);
	position.Y = std::fminf(position.Y, Window::HEIGHT - range);
	position.Y = std::fmaxf(0.0f + range, position.Y);

	SetSpeedToElder();
	if (moveCount > 0)return;
	state = STATE_STOP;
	OutOfElderRange(100) ? SetStopCount(0, 0) : SetStopCount(30, 60);
	target = NULL;
}

void EnemyInoshishi::CheckTargetPlayer()
{
	vector<int>pl = managers->Player()->GetEnablePlayerIndexList();
	int plNum = pl.size();
	target = NULL;
	if (plNum <= 0)return;

	float range = 100.0f;

	for (int i = 0; i < plNum; i++)
	{
		Vec2 pPos = managers->Player()->GetPlayerData(i)->GetPosition();
		Vec2 vec = pPos - position;

		bool isRange = vec.Length() < range;

		if (isRange)
		{
			SetTarget(pl[i]);
			break;
		}
	}
}

void EnemyInoshishi::SetTarget(int targetIndex)
{
	this->target = managers->Player()->GetPlayerData(targetIndex);
}

void EnemyInoshishi::DamageAction(HitData hitData){
	parameter.speed *= (1.0 / 2);
	moveCount = 0;
}

void EnemyInoshishi::SetSpeedToPlayer()
{
	if (target == NULL)return;

	speed = target->GetPosition() - position;
	speed.NormalizeSelf();
	speed *= 10.0f;
	angle = atan2(speed.Y, speed.X);
}

HitData EnemyInoshishi::CalcAttackToPlayer(Vec2 posOther, double rangeOther){
	if (IsHitToPlayer(posOther, rangeOther)){
		parameter.speed *= (1.0 / 4);
		return HitData::Setup(position, parameter.pushPower, parameter.attackPower);
	}
	return HitData::NoHit();
}

void EnemyInoshishi::SetSpeed()
{
	SetAngle();
	speed = Vec2(cos(angle), sin(angle)) * 3.0f;
}

int EnemyInoshishi::GetGroupNum()
{
	return group;
}