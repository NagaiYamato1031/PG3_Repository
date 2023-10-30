#pragma once
class Enemy
{
public:
	
	void Initialize();

	void Update();

private:

	void Attack();

	void Shot();

	void BeingOut();

	void (Enemy::*pFunc)();

};

