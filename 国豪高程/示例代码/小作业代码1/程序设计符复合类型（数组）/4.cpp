#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int carID, a[10]{}, num, panduan;
	double zero = 0.0;
	for (int i = 0; i < 10; ++i) a[i] = 100;
	while (cin >> carID && carID != -1 && cin >> num)
	{
		panduan = 0;
		for (int i = 0; i < 10; i++)
		{
			if (a[i] == carID)
			{
				panduan = 1;
				num = i;
				break;
			}
			else if (panduan != 1 && i == 9 && a[num] != 100)
			{
				panduan = 0;
				carID = a[num];
			}
		}
		if (panduan == 0 && a[num] == 100)
		{
			a[num] = carID;
			cout << carID << "号车成功停靠在" << num << "号车位！" << endl;
		}
		else if (panduan == 1) cout << "该车已经停在" << num << "号车位了！" << endl;
		else if (panduan == 0 && a[num] != 100) cout << carID << "号车已经占据该车位了！" << endl;
	}
	return 0;
}