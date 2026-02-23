#include <iostream>
using namespace std;
int main()
{
	int a[4][4]{}, sumlie = 0, sumhang = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> a[i][j];
	for (int i = 0; i < 4; i++)
	{
		sumhang = 0;
		for (int j = 0; j < 4; j++)
		{
			sumhang += a[i][j];
		}
		cout << sumhang << ' ';
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		sumlie = 0;
		for (int j = 0; j < 4; j++)
		{
			sumlie += a[j][i];
		}
		cout << sumlie << ' ';
	}
	return 0;
}