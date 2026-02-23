#include <iostream>
using namespace std;
int main()
{
	char str[200]{};
	int pianyi = 0;
	cin.getline(str, 200);
	cin >> pianyi;
	for (int i = 0; i < strlen(str); i++)
	{
		int temp = str[i] + pianyi;
		if (str[i] >= 65 && str[i] <= 90)
		{
			if (temp > 90) str[i] = 64 + (temp - 90);
			else if (temp < 65) str[i] = 91 - (65 - temp);
			else str[i] = temp;
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			if (temp > 122) str[i] = 96 + (temp - 122);
			else if (temp < 97) str[i] = 123 - (97 - temp);
			else str[i] = temp;
		}
	}
	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i];
	}
}