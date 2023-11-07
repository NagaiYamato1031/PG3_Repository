#include "Rectangle.h"

#include <stdio.h>

void Rectangle::Size()
{
	size_ = width_ * height_;
}

void Rectangle::Draw()
{
	printf("横縦 : %.2f , %.2f\n", width_, height_);
	printf("面積 : %.2f\n", size_);
}
