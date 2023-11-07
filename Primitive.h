#pragma once
class IPrimitive 
{
public:

	IPrimitive();
	virtual ~IPrimitive();

	virtual void Print();
};

class Triangle : public IPrimitive
{
public:

	Triangle();
	~Triangle() override;

	void Print() override;
};

class Sphere : public IPrimitive
{
public:

	Sphere();
	~Sphere() override;

	void Print() override;
};