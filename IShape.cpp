#include "IShape.h"

#include <stdio.h>

void IShape::Draw()
{
	printf("面積は %.2f\n", size_);
}
