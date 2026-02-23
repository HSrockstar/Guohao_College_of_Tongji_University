#include <iostream>
#include <iomanip>
const int nAmount = 20;
using namespace std;
int main()
{
	int n[nAmount];
	for (int i = 0; i < nAmount; i++) cin >> n[i];
	for (int i = 1; i < nAmount; i++)
	{
		int temp = n[i];
		int j = i - 1;
		while (j >= 0 && n[j] > temp)
		{
			n[j+1] = n[j];
			j--;
		}
		n[j+1] = temp;
	}
	for (int i = 0; i < nAmount; i++) cout << n[i] << ' ';
	return 0;
}