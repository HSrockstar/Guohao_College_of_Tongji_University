#include <iostream>
using namespace std;
int main()
{
    int num = 0, i = -1;
    while (cin.fail() == 0) {
        cin >> num;
        i++;
    }
    cout << i;
    return 0;
}