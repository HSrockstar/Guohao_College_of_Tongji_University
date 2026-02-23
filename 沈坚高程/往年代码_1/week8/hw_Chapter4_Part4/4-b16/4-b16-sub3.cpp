/*2253893 信06 苗君文*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include<cmath>
using namespace std;
int case3(double a, double b, double c)//有两个相等的实根
{
	double x1;
	if (a != 0 && fabs(b * b - 4 * a * c) < 1e-6) {
		x1 = -b / (2 * a);
		if (fabs(x1) < 1e-6)
			x1 = 0;
		cout << "有两个相等实根：" << endl;
		cout << "x1=x2=" << x1 << endl;
	}
	return 0;
}
