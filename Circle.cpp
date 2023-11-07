#include "Circle.h"

#include <stdio.h>

void Circle::Size()
{
	size_ = radius_ * radius_ * 3.14f;
}

void Circle::Draw()
{
	printf("半径 : %.2f\n", radius_);
	printf("面積 : %.2f\n", size_);
}
