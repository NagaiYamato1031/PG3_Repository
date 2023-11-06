#include <stdio.h>

template<typename Ty1, typename Ty2>
class Calc {
public:

	Ty1 a_;
	Ty2 b_;

public:

	Calc(Ty1 a, Ty2 b) : a_(a), b_(b) {}

	Ty1 Min() {
		Ty1 castB = static_cast<Ty1>(b_);

		if (a_ < castB) {
			return a_;
		}
		else {
			return castB;
		}
	}
};


int main() {

	Calc<int, int> iICalc(1, 4);
	Calc<int, float> iFCalc(7, 5.0f);
	Calc<int, double> iDCalc(7, 8.5);

	Calc<float, float> fFCalc(1.0f, 5.0f);
	Calc<float, int> fICalc(2.2f, 5);
	Calc<float, double> fDCalc(10.5f, 8.5);

	Calc<double, double> dDCalc(1.11, 2.55);
	Calc<double, int> dICalc(6.0, 5);
	Calc<double, float> dFCalc(12.85, 12.0f);

	printf("i %d, i %d, 最小値 = %d \n", iICalc.a_, iICalc.b_, iICalc.Min());
	printf("i %d, f %4.2f, 最小値 = %d \n", iFCalc.a_, iFCalc.b_, iFCalc.Min());
	printf("i %d, d %lf, 最小値 = %d \n\n", iDCalc.a_, iDCalc.b_, iDCalc.Min());
	
	printf("f %4.2f, f %4.2f, 最小値 = %4.2f \n", fFCalc.a_, fFCalc.b_, fFCalc.Min());
	printf("f %4.2f, i %d, 最小値 = %4.2f \n", fICalc.a_, fICalc.b_, fICalc.Min());
	printf("f %4.2f, d %lf, 最小値 = %4.2f \n\n", fDCalc.a_, fDCalc.b_, fDCalc.Min());

	printf("d %lf, d %lf, 最小値 = %lf \n", dDCalc.a_, dDCalc.b_, dDCalc.Min());
	printf("d %lf, i %d, 最小値 = %lf \n", dICalc.a_, dICalc.b_, dICalc.Min());
	printf("d %lf, f %4.2f, 最小値 = %lf \n", dFCalc.a_, dFCalc.b_, dFCalc.Min());
	



	return 0;
}
