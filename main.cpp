#include <stdio.h>
#include "Enemy.h"


int main() {

	Enemy enemy;
	enemy.Initialize();

	while (1) {
		enemy.Update();
	}


	return 0;
}
