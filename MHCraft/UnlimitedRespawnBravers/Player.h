#ifndef _CHARACTER_PLAYER_H_
#define _CHARACTER_PLAYER_H_

#include "GSystemHub.h"
#include "DeviceManager.h"
#include "ICharacter.h"
#include "IAttackable.h"
#include "DamageAreaManager.h"
#include"Cutting.h"//å„Ç≈çÌèú

class Player : public ICharacter, public IAttackable
{
public:
	Player(int padNo, int health, int sp, float speed, IMAGE_ASSET_NAME assetName, PlayerColorList colors);
	~Player();
	void Initialize();
	void Update();
	void Draw();
	int	 GetImageHandle();
	int  GetPadNo();
	void SetupPlayer(int health, int sp, float speed, IMAGE_ASSET_NAME assetName, PlayerColorList colors);
	bool GetIsEnd();
	void HitDamage(HitData hitData);
	CharacterInformation GetParameter();
	GCircle GetHitArea();
	Vec2 GetPosition();
	int GetLeftHealth();
	void Damage(int damage);
	void Heal(int heal);
	bool FlashManager(int counter);

private:
	DeviceManager*			device;
	Managers*				managers;
	PlayerColorList			colors;
	AnimeData				animeData;
	CharacterInformation	parameter;
	int						padNo;
	int						cntHoldDirection;
	int						maxCntHoldDirection;
	int						imageHandle;
	int						imageType;
	int						direction;
	int						cntStop;
	int						cntAttack;
	int						cntInvincible;
	int						maxCntAttack;
	bool					isEnd;
	bool					isWalk;


	void SetPlayerColor(PlayerColorList colors);
	void SetAnimeData(AnimeData animeData);
	void LoadImageHandle(IMAGE_ASSET_NAME assetName);
	void Attack();
	void ChangeImageType(int type);
	void ChangeDirection(Vec2 moveTo);
	void Move();
	Vec2 MoveVector();
	void SetIsEnd();
	void CalcReceiveAttack();
	void SetDamageArea();
	void Knockback(Vec2 fromPos, Vec2 toPos, int power);
	void Knockback(double angleRad, int power);
	void CheckIsDead();
	void CheckIsOverHeal();
	void CountDeadTimer();
	void CountdownInvincible();
	void Clamp();
};

#endif


