#pragma once
#include "IShape.h"

class Circle : public IShape
{
private:

	float radius_;

public:

	Circle(float radius) : IShape() , radius_(radius) {}

	void Size() override;
	void Draw() override;
};

