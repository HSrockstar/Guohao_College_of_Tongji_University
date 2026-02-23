#include <iostream>
using namespace std;
int main()
{
	int shijinzhi;
	string erjinzhi = "00000000";
	cin >> shijinzhi;
	for (int i = 7; i >= 0; i--) {
		if (shijinzhi % 2 == 0) erjinzhi[i] = '0';
		else erjinzhi[i] = '1';
		shijinzhi /= 2;
	}
	cout << erjinzhi;
}