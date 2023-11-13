#include "Enemy.h"
#include <stdio.h>
#include <Windows.h>

void Enemy::Initialize()
{
	pFunc[0] = &Enemy::Attack;
	pFunc[1] = &Enemy::Shot;
	pFunc[2] = &Enemy::BeingOut;

	funcNo_ = 0;
}

void Enemy::Update()
{
	(this->*pFunc[funcNo_])();
	Sleep(2000);
}

void Enemy::Attack()
{
	printf("近接\n");
	//pFunc = &Enemy::Shot;
	funcNo_++;
}

void Enemy::Shot()
{
	printf("射撃\n");
	//pFunc = &Enemy::BeingOut;
	funcNo_++;
}

void Enemy::BeingOut()
{
	printf("離脱\n");
	//pFunc = &Enemy::Attack;
	funcNo_ = 0;
}
