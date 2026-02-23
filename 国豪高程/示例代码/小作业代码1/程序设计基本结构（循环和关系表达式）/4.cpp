#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double n = 0, e = 1.0, fenmu = 1.0;
    cin >> n;
    for (double i = 1; i < (n + 1); i++) {
        fenmu *= i;
        e += 1 / fenmu;
    }
    cout << fixed << setprecision(10) << e;
    return 0;
}