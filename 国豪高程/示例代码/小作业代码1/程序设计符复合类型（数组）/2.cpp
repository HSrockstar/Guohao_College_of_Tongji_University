#include <iostream>
using namespace std;
int main()
{
	int a[10]{}, b[100]{}, k = 0;
	for (int i = 0; i < 10; i++) cin >> a[i];
	while (cin >> b[k] && b[k] != -1) k++;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (b[i] == a[j])
			{
				cout << b[i] << "在数组中。" << endl;
				break;
			}
			else if (j == 9) cout << b[i] << "不在数组中。" << endl;
		}
	}
	return 0;
}