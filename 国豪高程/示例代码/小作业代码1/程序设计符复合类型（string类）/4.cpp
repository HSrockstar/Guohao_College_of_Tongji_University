#include <iostream>
#include <string>
using namespace std;
void skipSpace(const string& str, int& i)
{
	bool has_space = false;
	i++;
	while (str[i] == ' ')
	{
		i++;
		has_space = true;
	}
}
int main()
{
	string str;
	getline(cin, str);
	bool isLegal = true;
	// 思路：从左往右进行判断
	// 开始：判断到'['，跳过空格，若否则非法
	// 循环判断
	// 1. 判断到数字，跳过空格，若','（continue），若']'（break），else非法
	// 2. 判断到'['，跳过空格，
	int i = 0, num = 0, panduan = 0;// num为左括号-右括号，最后要为0
	if (str[i] != '[') isLegal = false;
	while (str[i])
	{
		if (str[i] == '[')
		{
			num++;
			panduan = 1;
		}
		else if (str[i] == ']')
		{
			num--;
			if (num == 0 && str[i + 1] != '\0') isLegal = false;
			panduan = 2;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			panduan = 3;
		}
		else if (str[i] == ',')
		{
			panduan = 4;
		}
		switch (panduan)
		{
		case 1:
			skipSpace(str, i);
			if (str[i] == ']' || (str[i] >= '0' && str[i] <= '9') || str[i] == '[') break;
			else isLegal = false;
			break;
		case 2:
			skipSpace(str, i);
			if (num == 0) break;
			else if (num != 0 && (str[i] == ',' || str[i] == ']')) break;
			else isLegal = false;
			break;
		case 3:
			while (str[i + 1] >= '0' && str[i + 1] <= '9')
			{
				i++;
			}
			skipSpace(str, i);
			if (str[i] == ']' || str[i] == ',') break;
			else
			{
				isLegal = false;
				break;
			}
			break;
		case 4:
			skipSpace(str, i);
			if (str[i] == '[' || (str[i] >= '0' && str[i] <= '9')) break;
			else isLegal = false;
			break;
		}
		if (num == 0 || !isLegal) break;
	}
	if (isLegal) cout << "格式合法！";
	else cout << "格式非法！";
	return 0;
}