#include <iostream>
using namespace std;
int main()
{
	int arr[5] = {};
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
	char* p = (char*)arr;
	for (int i = 0; i < 20; i++)
	{
		cout << (int)*(p + i) << " ";
	}
	return 0;
}