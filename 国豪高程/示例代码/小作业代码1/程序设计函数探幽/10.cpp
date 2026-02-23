#include <iostream>
#include <string>
using namespace std;
int map[9][9]{};
bool visit[9][9]{ false };
bool isFound = false;
bool isVisited = false;
void escape(int row, int col, int tRow, int tCol)
{
	if (row < 0 || row >= 9 || col < 0 || col >= 9) return;
	if (visit[row][col] || map[row][col] == 0) return;
	visit[row][col] = true;
	if (row == tRow && col == tCol)
	{
		isFound = true;
		cout << row << "," << col << endl;
		return;
	}
	// 上
	escape(row - 1, col, tRow, tCol);
	if (isFound)
	{
		cout << row << "," << col << endl;
		return;
	}
	// 下
	escape(row + 1, col, tRow, tCol);
	if (isFound)
	{
		cout << row << "," << col << endl;
		return;
	}
	// 左
	escape(row, col - 1, tRow, tCol);
	if (isFound)
	{
		cout << row << "," << col << endl;
		return;
	}
	// 右
	escape(row, col + 1, tRow, tCol);
	if (isFound)
	{
		cout << row << "," << col << endl;
		return;
	}
	// 不通，终止
	visit[row][col] = false;
}
int main()
{
	int row, col;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> map[i][j];
	cin >> row >> col;
	int target_row = 0, target_col = 0;
	for (int i = 0; i < 9; i++)
	{
		if (map[0][i] == 1)
		{
			target_row = 0;
			target_col = i;
			break;
		}
		if (map[8][i] == 1)
		{
			target_row = 8;
			target_col = i;
			break;
		}
		if (map[i][0] == 1)
		{
			target_row = i;
			target_col = 0;
			break;
		}
		if (map[i][8] == 1)
		{
			target_row = i;
			target_col = 8;
			break;
		}
	}
	escape(target_row, target_col, row, col);
	return 0;
}