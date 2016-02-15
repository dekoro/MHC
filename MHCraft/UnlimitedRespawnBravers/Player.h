#ifndef _CHARACTER_PLAYER_H_
#define _CHARACTER_PLAYER_H_

#include "GSystemHub.h"
#include "DeviceManager.h"
#include "ICharacter.h"
#include "IAttackable.h"
#include "DamageAreaManager.h"

class Player : public ICharacter, public IAttackable
{
public:
	Player(int playerNo);
	~Player();
	void	Setup(CharacterInformation parameter);
	void	Initialize();
	void	Update();
	void	Draw();
	int		GetImageHandle();
	void	KnockbackDamage(HitData hitData);
	CharacterInformation GetParameter();
	GCircle	GetHitArea();
	Vec2	GetPosition();
	int		GetLeftHealth();
	float	GetLeftHealthPercent(int digits);
	void	Heal(int heal);
	void	Dispone();

private:
	DeviceManager*			device;
	PlayerColorList			colors;
	AnimeData				animeData;
	CharacterInformation	parameter;

	int		padNo;
	int		cntHoldDirection;
	int		maxCntHoldDirection;
	int		imageHandle;
	int		imageType;
	int		direction;
	int		cntStop;
	int		cntAttack;
	int		cntInvincible;
	int		maxCntAttack;
	bool	isEnable;
	bool	isWalk;

	void	Damage(int damage);
	void SetPlayerColor(PlayerColorList colors);
	void SetAnimeData(AnimeData animeData);
	void LoadImageHandle(IMAGE_ASSET_NAME assetName);
	void Attack();
	void ChangeImageType(int type);
	void ChangeDirection(Vec2 moveTo);
	void Move();
	Vec2 MoveVector();
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


