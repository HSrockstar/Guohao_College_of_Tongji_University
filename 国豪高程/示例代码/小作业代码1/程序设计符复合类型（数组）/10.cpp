#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[3][3]{}, b[5][5]{};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			b[i][j] = a[i / 2][j / 2];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j % 2 != 0)
			{
				b[i][j] = (b[i][j - 1] + b[i][j + 1]) / 2;
			}
			if (i % 2 != 0)
			{
				b[i][j] = (b[i - 1][j] + b[i + 1][j]) / 2;
			}
			if ((j % 2 != 0) && (i % 2 != 0))
			{
				b[i][j] = (b[i - 1][j - 1] + b[i - 1][j + 1] + b[i + 1][j - 1] + b[i + 1][j + 1]) / 4;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}