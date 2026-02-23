#include <iostream>
using namespace std;
int main()
{
	char pan[5][5], move;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> pan[i][j];
		}
	}
	cin >> move;
	if (move == 'W')
	{
		for (int i = 0; i < 5; i++)
		{
			int index = 0;
			for (int j = 0; j < 5; j++)
			{
				if (pan[j][i] != '*')
				{
					swap(pan[j][i], pan[index][i]);
					index++;
				}
			}
		}
	}
	if (move == 'A')
	{
		for (int i = 0; i < 5; i++)
		{
			int index = 0;
			for (int j = 0; j < 5; j++)
			{
				if (pan[i][j] != '*')
				{
					swap(pan[i][j], pan[i][index]);
					index++;
				}
			}
		}
	}
	if (move == 'S')
	{
		for (int i = 0; i < 5; i++)
		{
			int index = 4;
			for (int j = 4; j >= 0; j--)
			{
				if (pan[j][i] != '*')
				{
					swap(pan[j][i], pan[index][i]);
					index--;
				}
			}
		}
	}
	if (move == 'D')
	{
		for (int i = 0; i < 5; i++)
		{
			int index = 4;
			for (int j = 4; j >= 0; j--)
			{
				if (pan[i][j] != '*')
				{
					swap(pan[i][j], pan[i][index]);
					index--;
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << pan[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}