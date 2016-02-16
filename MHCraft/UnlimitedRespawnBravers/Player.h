#ifndef _CHARACTER_PLAYER_H_
#define _CHARACTER_PLAYER_H_

#include "GSystemHub.h"
#include "ICharacter.h"
#include "IAttackable.h"
#include "DamageAreaManager.h"
#include "Cutting.h"//å„Ç≈çÌèú
#include <memory>

class DeviceManager;

class Player : public ICharacter, public IAttackable
{
public:
	Player(int padNo);
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
	void	Damage(int damage);
	void	Heal(int heal);
	float	GetLeftHealthPercent(int digits);
	bool	FlashManager(int counter);
	void	Spawn(Vec2 position);
	int		GetPadNo();
	void	Dispone();
	Vec2	GetPosition();
	void	Attack(float angleDig, int chargeLevel);
	void	Move(Vec2 velocity, float multiply=1.0f);

private:	
	DeviceManager*				device;
	AnimeData					animeData;
	CharacterInformation		parameter;
	std::shared_ptr<Cutting>	cut;
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
	void	CountdownInvincible();\
	void	Clamp();
};

#endif


