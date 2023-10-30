#include "Enemy.h"
#include <stdio.h>
#include <Windows.h>

void Enemy::Initialize()
{
	pFunc = &Enemy::Attack;
}

void Enemy::Update()
{
	(this->*pFunc)();
	Sleep(2000);
}

void Enemy::Attack()
{
	printf("近接\n");
	pFunc = &Enemy::Shot;
}

void Enemy::Shot()
{
	printf("射撃\n");
	pFunc = &Enemy::BeingOut;
}

void Enemy::BeingOut()
{
	printf("離脱\n");
	pFunc = &Enemy::Attack;
}
