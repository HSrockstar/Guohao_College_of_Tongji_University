#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int i = 0, b[101]{};
	double sum = 0.0, renshu = 0.0;
	int n = 0;
	double a[101]{};
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
			else if (renshu >= 10 && a[i] > (sum / 10.0))
			{
				double min = 5.0;
				for (int j = 0; j <= i; j++)
				{
					if (b[j] == 1 && min > a[j])
					{
						min = a[j];
						n = j;
					}
				}
				sum -= a[n];
				a[n] = a[i];
				sum += a[i];
				i++;
			}
			else
			{
				b[i] = 0;
				i++;
			}
		}
		else break;
	}
	double c[101]{};
	int m = 0;
	for (int j = 0; j < i; j++)
	{
		if (b[j] == 1)
		{
			c[m] = a[j];
			m++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		double temp = c[i];
		int j = i - 1;
		while (j >= 0 && c[j] < temp)
		{
			c[j + 1] = c[j];
			j--;
		}
		c[j + 1] = temp;
	}
	for (int i = 0; i <= m; i++) cout << fixed << setprecision(2) << c[i] << ' ';
	double avg = sum / renshu;
	cout << endl << avg;
	return 0;
}