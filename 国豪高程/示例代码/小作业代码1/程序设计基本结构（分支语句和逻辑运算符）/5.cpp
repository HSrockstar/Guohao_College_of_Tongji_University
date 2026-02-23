#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int hour, min;
	cin >> hour >> min;
	int total_min = hour * 60 + min;
	if (total_min >= (15 * 60 + 30) && total_min < (16 * 60 + 15)) cout << (17 * 60 + 5 - total_min);
	else if (total_min >= (16 * 60 + 20) && total_min < (17 * 60 + 5)) cout << (17 * 60 + 5 - total_min);
	else cout << 0;
	return 0;
}