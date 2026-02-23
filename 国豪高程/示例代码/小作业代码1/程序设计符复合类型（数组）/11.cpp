#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a[9][9]{}, row, line, light;
	while (cin >> row && row != -1 && cin >> line >> light)
	{
		a[row][line] = 10000;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int distance = abs(i - row) + abs(j - line);
				if (a[i][j] != 10000)
				{
					if (distance < light && a[i][j] <= light - distance)
					{
						a[i][j] = light - distance;
					}
				}
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (a[i][j] == 10000) cout << '*' << ' ';
			else cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}