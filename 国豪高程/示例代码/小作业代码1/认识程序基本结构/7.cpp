#include <iostream>
using namespace std;
double d, t;
const double v = 0.01;
double getDistance() {
	cin >> d;
	return d;
}
double time() {
	t = d / v;
	return t;
}
double out() {
	cout << t;
	return t;
}
int main()
{
	getDistance();
	time();
	out();
}