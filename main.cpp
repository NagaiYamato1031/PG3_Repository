#include <stdio.h>

#include "Primitive.h"

int main() {

	const size_t kPrimitiveNum = 4;

	IPrimitive* primitives[4];
	
	for (size_t i = 0; i < kPrimitiveNum - 1; i++)
	{
		primitives[i] = new Triangle();
	}
	primitives[kPrimitiveNum - 1] = new Sphere();


	for (size_t i = 0; i < kPrimitiveNum; i++)
	{
		primitives[i]->Print();
	}

	for (size_t i = 0; i < kPrimitiveNum; i++)
	{
		delete primitives[i];
	}

	return 0;
}
