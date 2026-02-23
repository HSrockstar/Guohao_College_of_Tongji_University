#include <iostream>
using namespace std;
int main()
{
	char str1[200]{}, str2[200]{};
	cin.getline(str1, 200);
	cin.getline(str2, 200);
	for (int i = 0; str2[i] != '\0'; i++)
	{
		int j = 0;
		while (str1[j] != '\0')
		{
			if (str1[j] == str2[i])
			{
				for (int k = j; str1[k] != '\0'; k++)
				{
					str1[k] = str1[k + 1];
				}
			}
			else j++;
		}
	}
	if (str1[0] == '\0') cout << "¿Õ´®";
	else cout << str1;
	return 0;
}