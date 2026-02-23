#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int N = 0;
    cin >> N;
    double a = 0.0, b = 0.0, sum1 = 0.0, sum2 = 0.0, avg = 0.0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        sum1 += a * b;
        sum2 += a;
        avg = sum1 / sum2;
        cout << setiosflags(ios::fixed) << setprecision(2) << avg;
    }
    return 0;
}