#include <iostream>
using namespace std;
int a[100];
int main()
{
    int N = 0, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        sum += a[i];
    }
    cout << sum;
    return 0;
}