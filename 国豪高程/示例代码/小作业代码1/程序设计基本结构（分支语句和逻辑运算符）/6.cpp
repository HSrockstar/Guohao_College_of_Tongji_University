#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a, b, sum=0;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		if (i % 10 == 7 || i % 7 == 0 || i / 10 % 10 == 7 || i / 100 % 10 == 7 || i / 1000 % 10 == 7 || i / 10000 % 10 == 7)
		{
			sum++;
			cout << i << " ";
		}
	}
	cout << endl << sum;
	return 0;
}