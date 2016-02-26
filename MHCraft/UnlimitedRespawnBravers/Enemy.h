#ifndef _CHARACTER_ENEMY_IENEMY_H_
#define _CHARACTER_ENEMY_IENEMY_H_

#include "GSystemHub.h"
#include "ICharacter.h"
#include "IAttackable.h"
#include "Player.h"
#include "DeviceManager.h"
#include "Managers.h"
#include "PlayerManager.h"

#include"CutEffect.h"

class Enemy
{
public:
	Enemy(vector<Enemy*>* enemyList, IMAGE_ASSET_NAME assetName);
	virtual ~Enemy();

	void					SetupData(Vec2 startPos, CharacterInformation chParam, bool isKnockback = true);
	CharacterInformation	GetParameter();
	Vec2					GetPosition();
	virtual void			Initialize()	= 0;
	virtual void			Draw()			= 0;
	virtual HitData			CalcAttackToPlayer(Vec2 posOther, double rangeOther) = 0;
	virtual void			DamageAction(HitData hitData) = 0;
	virtual void			DeadPlayerAction(){}
	virtual void			Update();
	virtual void			ResearchTarget(int forbiddenTarget=-1);
	virtual void			GetTarget(int forbiddenTarget=-1);
	virtual void			CalcDamage(HitData hitData);
	bool					GetIsUse();
	bool					GetIsDead();
	IMAGE_ASSET_NAME		GetAssetName();

protected:
	DeviceManager*			device;
//	Managers*				managers;
	Player*					target;
	ImageData*				imageData;
	Vec2					position;
	CharacterInformation	parameter;
	IMAGE_ASSET_NAME		assetName;
	int						cntDead;
	bool					isUse;
	bool					isDead;
	bool					isInvincible;
	bool					isKnockBack;
	bool					IsHitToPlayer(Vec2 posOther, double rangeOther);
	virtual void			CountDeadTimer();
protected:
	virtual void Damage(int damage);
	void Heal(int Heal);
	void CheckIsDead();
	CutEffect cutEffect;
private:

	void SetTarget(int targetIndex);
	void CheckHitDamageArea();
	void GetRandomTarget(int forbiddenTarget);
	void CheckIsOverHeal();
	void Knockback(Vec2 fromPos, Vec2 toPos, int power);
	void Knockback(double angleRad, int power);


};


#endif



