#include <iostream>
using namespace std;
int main()
{
	char str[200]{};
	int num = 0;
	cin.getline(str, 200);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			num++;
			str[i] = str[i] - ('a' - 'A');
		}
	}
	cout << num << endl;
	for (int i = 0; i < strlen(str); i++) cout << str[i];
	return 0;
}