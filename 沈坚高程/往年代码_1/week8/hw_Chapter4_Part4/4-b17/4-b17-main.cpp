/*2253893 信06 苗君文*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include<cmath>
using namespace std;
double a, b, c;
int main()
{
	void case1();
	void case2();
	void case3();
	void case4();
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	case1();
	case2();
	case3();
	case4();
	return 0;
}