#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int i = 0, b[101] = {};
	double sum = 0.0, renshu = 0.0;
	double a[101] = {};
	while (true)
	{
		cin >> a[i];
		if (a[i] != -1)
		{
			if (renshu == 0.0)
			{
				if (a[i] >= 3.5)
				{
					sum += a[i];
					b[i] = 1;
					renshu++, i++;
				}
				else
				{
					b[i] = 0;
					i++;
				}
			}
			else if (renshu >= 0 && renshu < 10)
			{
				if (a[i] > (sum / renshu))
				{
					sum += a[i];
					b[i] = 1;
					renshu++, i++;
				}
				else
				{
					b[i] = 0;
					i++;
				}
			}
			else
			{
				b[i] = 0;
				i++;
			}
		}
		else break;
	}
	for (int j = 0; j < i; j++)
	{
		if (b[j] == 1) cout << fixed << setprecision(2) << a[j] << "被录用了。\n";
		else cout << fixed << setprecision(2) << a[j] << "未被录用。\n";
	}
	return 0;
}