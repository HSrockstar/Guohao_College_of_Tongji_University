#include <iostream>
using namespace std;
int main()
{
	unsigned int n1, n2, panduan = 0;
	cin >> n1 >> n2;
	unsigned int n = n1;
	while (n <= n2)
	{
		for (unsigned int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				panduan = 1;
				break;
			}
			else panduan = 0;
		}
		if (panduan == 0) cout << n << " ";
		n++;
	}
	return 0;
}