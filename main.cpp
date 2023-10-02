#include <stdio.h>


template<typename Ty>
Ty Min(Ty a, Ty b) {
	return a < b ? a : b;
}

template<>
char Min<char>(char a, char b) {
	printf("数字以外は代入できません\n");
	return '\0';
}


int main() {


	int a = 10, b = 30;
	float c = 2.4f, d = 3.5f;
	double e = 28.78, f = 28.51;
	char g = '1', h = '2';


	printf("二つの値のMinを取得\n\n");

	printf("int	 %d %d		: %d\n", a, b, Min(a, b));
	printf("float	 %.2f %.2f	: %.2f\n", c, d, Min(c, d));
	printf("double %.2lf %.2lf: %.2lf\n", e, f, Min(e, f));
	Min(g, h);

	return 0;
}
