#include <iostream>
using namespace std;
int main()
{
	double a = 0;
	cin >> a;
	int zhengshu = static_cast<int>(a);
	double xiaoshu = a - zhengshu;
	cout << zhengshu << " " << xiaoshu;
	return 0;
}