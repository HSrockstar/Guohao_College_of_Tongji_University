#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	int N;
	cin >> N;
	if(cin.fail() == 0)
	{
		if(N % 4 == 0) {
			if(N % 100 == 0) {
				if(N % 400 == 0)
					cout << N << "年是闰年。";
				else cout << N << "年不是闰年。";
			}
			else cout << N << "年是闰年。";
		}
		else cout << N << "年不是闰年。";
	}
	else cout << "输入错误";
	return 0;
}