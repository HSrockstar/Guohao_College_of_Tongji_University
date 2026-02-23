#include <iostream>
using namespace std;
int sumDay(int birth, int now) {
	int sumDay = (now - birth) * 365;
	return sumDay;
}
int main()
{
	int N1, N2;
	cin >> N1 >> N2;
	int day = sumDay(N1, N2);
	cout << day;
}