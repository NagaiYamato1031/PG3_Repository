#include "Primitive.h"

#include <stdio.h>

IPrimitive::IPrimitive()
{
}

IPrimitive::~IPrimitive()
{
	
}

void IPrimitive::Print()
{
	printf("図形 : Primitive\n");
}




Triangle::Triangle()
{
}

Triangle::~Triangle()
{
}

void Triangle::Print()
{
	printf("図形 : Triangle\n");
}


Sphere::Sphere()
{
}

Sphere::~Sphere()
{
}

void Sphere::Print()
{
	printf("図形 : Sphere\n");
}