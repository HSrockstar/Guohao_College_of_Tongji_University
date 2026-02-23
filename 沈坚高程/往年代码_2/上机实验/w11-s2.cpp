/*2253744 林觉凯 软工 */
#include <iostream>
using namespace std;
void sort(int array[], int n)
{
	int i, j, k, t;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] > array[k])
			{
				k = j;
			}
		}
		t = array[k];
		array[k] = array[i];
		array[i] = t;
	}
}
int main()
{
	int number[1001] = { 0 };
	int i = 0;
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	for (; i < 1000; i++)
	{
		int tempnumber;
		cin >> tempnumber;
		number[i] = tempnumber;
		if (tempnumber < 0)
		{
			break;
		}
	}
	i--;
	if (i < 0)
	{
		cout << "无有效输入" << endl;
		return 0;
	}
	else
	{
		cout << "输入的数组为:" << endl;
	}
	int flag = 0;
	for (int j = 0; j < i + 1; j++)
	{
		cout << number[j] << ' ';
		flag++;
		if (flag == 10)
		{
			cout << endl;
			flag = 0;
		}
	}
	cout << endl;
	cout << "分数与排名的对应关系为:" << endl;
	sort(number, i + 1);
	for (int j = 0; j < i + 1;)
	{
		int value = number[j];
		int count = 0;
		for (int k = j; k < i + 1; k++)
		{
			if (number[k] == value)
			{
				cout << value << ' ' << j + 1 << endl;
				count++;
			}
			else
			{
				break;
			}
		}
		j += count;
	}
	return 0;
}
/*
测试数据，可复制后粘贴到运行窗口中
87 86 56 76 87 92 76 0 96 98 0 23 -1

87 86 56 76 87 92 76 96 98 23 55 56 34 23 -1
*/
