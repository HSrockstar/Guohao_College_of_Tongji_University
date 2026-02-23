/*2253893 信06 苗君文*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include<cmath>
using namespace std;
int case1(double a, double b, double c)//a为0
{
	if(a==0)
		cout << "不是一元二次方程" << endl;
	return 0;
}
int case2(double a, double b, double c)//有两个不等的实根
{
	double x1, x2;
	if (a != 0 && b * b - 4 * a * c >= 1e-6) {
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		if (fabs(x1) < 1e-6)
			x1 = 0;
		if (fabs(x2) < 1e-6)
			x2 = 0;
		cout << "有两个不等实根：" << endl;
		cout << "x1=" << x1 << endl;
		cout << "x2=" << x2 << endl;
	}
	return 0;
}
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
int case4(double a, double b, double c)//有两个虚根
{
	double y, i1;
	if (a != 0 && 4 * a * c - b * b >= 1e-6) {
		y = -b / (2 * a);
		if (fabs(y) < 1e-6)
			y = 0;
		i1 = fabs(sqrt(4 * a * c - b * b) / (2 * a));
		if (fabs(i1) < 1e-6)
			i1 = 0;
		cout << "有两个虚根：" << endl;
		if (fabs(i1 - 1) < 1e-6) {
			if (y == 0) {
				cout << "x1=" << "i" << endl;
				cout << "x2=-" << "i" << endl;
			}
			else {
				cout << "x1=" << y << "+" << "i" << endl;
				cout << "x2=" << y << "-" << "i" << endl;
			}
		}
		else {
			if (y == 0) {
				cout << "x1=" << i1 << "i" << endl;
				cout << "x2=-" << i1 << "i" << endl;
			}
			else {
				cout << "x1=" << y << "+" << i1 << "i" << endl;
				cout << "x2=" << y << "-" << i1 << "i" << endl;
			}
		}
	}
	return 0;
}

int main()
{
	double a, b, c;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	case1(a, b, c);
	case2(a, b, c);
	case3(a, b, c);
	case4(a, b, c);
	return 0;
}