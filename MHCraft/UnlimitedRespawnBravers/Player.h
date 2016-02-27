#ifndef _CHARACTER_PLAYER_H_
#define _CHARACTER_PLAYER_H_

#include "GSystemHub.h"
#include "ICharacter.h"
#include "IAttackable.h"
#include "Cutting.h"//後で削除
#include "InputState.h"
#include "Laser.h"
#include"AnimeDirection.h"

class AbstractDamageArea;
class DeviceManager;
class DamageAreaManager;
class DamageAreaCircle;
class LaserManager;



class Player : public ICharacter, public IAttackable
{
public:
	Player(int padNo, LaserManager* laserManager, DamageAreaManager* damageAreaManager);
	~Player();
	void	Initialize();
	void	Update();
	void	Draw();
	void	Finalize();
	int		GetImageHandle();
	void	Setup(CharacterInformation parameter);
	bool	IsEnable();
	void	HitDamage(HitData hitData);
	CharacterInformation GetParameter();
	GCircle	GetHitArea();
	int		GetLeftHealth();
	float	GetLeftHealthPercent(int digits);
	void	Damage(int damage);
	void	Heal(int heal);
	bool	FlashManager(int counter);
	void	Spawn(Vec2 position);
	int		GetPadNo();
	void	Dispone();
	Vec2	GetPosition();
	void	CheckHitDamageArea(AbstractDamageArea* damageArea);
	Vec2	GetCenterPosition();

private:	
	DeviceManager*				device;
	InputState*					inputState;
	DamageAreaManager*			damageAreaManager;
	LaserManager*				laserManager;
	AnimeData					animeData;
	CharacterInformation		parameter;
	DamageAreaCircle*			hitArea;
	std::shared_ptr<Cutting>	cut;
	LaserData					laserData;
	AnimeDirection motion;
	e_Motion state;//プレイヤーの状態
	e_Motion oldState;//プレイヤーの状態
	e_AnimeDirection dairection;

	int		width;
	int		height;
	int		padNo;
	int		imageHandle;
	int		imageType;
	int		cntStop;
	int		cntDead;
	int		cntInvincible;
	int		countAddForbidden;
	int		maxStopCntAttack;
	int		maxStopCntDamage;
	bool	isEnable;
	bool	isWalk;

	void	CheckControll();
	void	SetAnimeData(AnimeData animeData);
	void	SetDamageArea();
	void	LoadImageHandle(IMAGE_ASSET_NAME assetName);
	void	ChangeImageType(int type);
	void	SetPlayAnimation(Vec2 velocity);
	void	SetIsEnd();
	void	Knockback(Vec2 fromPos, Vec2 toPos, int power);
	void	Knockback(double angleRad, int power);
	void	CheckIsDead();
	void	CheckIsOverHeal();
	void	CountDeadTimer();
	void	CountdownInvincible();
	void	Clamp();
	void	ControllManager();
	void	Attack(Vec2 vector, int chargeLevel);
	void	Move(Vec2 velocity, float multiply=1.0f);
	void    CheckDirection(Vec2 velocity);
};

#endif


