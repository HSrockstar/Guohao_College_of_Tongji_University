/*2253744 林觉凯 软工*/
#include <iostream>
#define MAXN 10001
using namespace std;
int is_power(int num, int base)
{
	int ret = 0;
	if (num == 1)
	{
		ret = 1;
	}
	if (num % base == 0)
	{
		ret = is_power(num / base, base);
		if ((num + 0.0) / base == base)
		{
			ret = 1;
		}
	}
	return ret;
}
int main()
{
	int arr[MAXN];
	int number;
	int base;
	cout << "请输入数据的个数[1..10000]" << endl;
	cin >> number;
	cout << "请输入" << number << "个正整数" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> arr[i];
	}
	cout << "请输入基数[2..9]" << endl;
	cin >> base;
	int count = 0;
	for (int i = 0; i < number; i++)
	{
		if (is_power(arr[i], base))
		{
			count++;
		}
	}
	cout << number << "个数中基数" << base << "的幂的个数 : " << count << endl;
	return 0;
}