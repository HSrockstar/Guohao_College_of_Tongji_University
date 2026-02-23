#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[8][8]{}, b[4][4]{}, line = 0, row = 0, max = -10000;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> a[i][j];
	while (line <= 6)
	{
		while (row <= 6)
		{
			max = -10000;
			for (int i = line; i <= line + 1; i++)
			{
				for (int j = row; j <= row + 1; j++)
				{
					if (max <= a[i][j]) max = a[i][j];
				}
			}
			b[line / 2][row / 2] = max;
			row += 2;
		}
		line += 2;
		row = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) cout << b[i][j] << ' ';
		cout << endl;
	}
	return 0;
}