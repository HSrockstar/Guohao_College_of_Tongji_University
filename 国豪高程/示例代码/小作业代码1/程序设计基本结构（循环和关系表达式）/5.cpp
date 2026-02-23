#include <iostream>
using namespace std;
int main()
{
    long long n = 0, a1 = 0, a2 = 1, a = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a = a1 + a2;
        a1 = a2;
        a2 = a;
    }
    cout << a1;
}