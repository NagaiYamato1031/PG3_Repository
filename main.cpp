#include <stdio.h>

#include "Circle.h"
#include "Rectangle.h"

int main() {

	const size_t kShapeNum = 3;

	IShape* shapes[kShapeNum];

	for (size_t i = 0; i < kShapeNum; i++)
	{
		if (i < kShapeNum - 1) {
			shapes[i] = new Circle(i + 1);
		}
		else {
			shapes[i] = new Rectangle(3, 2);
		}
	}

	for (size_t i = 0; i < kShapeNum; i++)
	{
		shapes[i]->Size();
		shapes[i]->Draw();
	}

	for (size_t i = 0; i < kShapeNum; i++)
	{
		delete shapes[i];
	}

	return 0;
}
