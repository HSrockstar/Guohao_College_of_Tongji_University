#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[5][5]{}, x, y;
	while (cin >> x && x != -1 && cin >> y)
	{
		x++;
		y++;
		switch (a[x][y])
		{
		case 0:
			a[x][y] = 1;
			break;
		case 1:
			a[x][y] = 0;
			break;
		}
		switch (a[x - 1][y])
		{
		case 0:
			a[x - 1][y] = 1;
			break;
		case 1:
			a[x - 1][y] = 0;
			break;
		}
		switch (a[x + 1][y])
		{
		case 0:
			a[x + 1][y] = 1;
			break;
		case 1:
			a[x + 1][y] = 0;
			break;
		}
		switch (a[x][y - 1])
		{
		case 0:
			a[x][y - 1] = 1;
			break;
		case 1:
			a[x][y - 1] = 0;
			break;
		}
		switch (a[x][y + 1])
		{
		case 0:
			a[x][y + 1] = 1;
			break;
		case 1:
			a[x][y + 1] = 0;
			break;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}