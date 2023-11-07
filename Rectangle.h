#pragma once

#include "IShape.h"

class Rectangle : public IShape
{
private:

	float width_;
	float height_;

public:

	Rectangle(float width, float height) : IShape(), width_(width), height_(height) {}

	void Size() override;
	void Draw() override;

};

