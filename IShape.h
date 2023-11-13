#pragma once
class IShape
{
protected:

	float size_;

public:
	IShape() : size_(0) {}

	virtual void Size() = 0;
	virtual void Draw() = 0;

};

