#include <iostream>
#include <string>
using namespace std;
int num[1000001];
int main() {
    string a, b, A, B;
    cin >> a >> b;
    A = a;
    B = b;
    size_t asize = a.size();
    size_t bsize = b.size();
    int aSize = static_cast<int>(asize);
    int bSize = static_cast<int>(bsize);
    for (int i = aSize - 1; i >= 0; i--)
    {
        A[i] = a[aSize - 1 - i];
    }
    for (int i = bSize - 1; i >= 0; i--)
    {
        B[i] = b[bSize - 1 - i];
    }
    int i = 0, ANum, BNum, numNum;
    bool jinwei = false;
    while (true)
    {
        ANum = 0;
        BNum = 0;
        numNum = 0;
        if (i < aSize)
        {
            ANum = A[i] - '0';
        }
        if (i < bSize)
        {
            BNum = B[i] - '0';
        }
        if (i > aSize && i > bSize) break;
        if (jinwei) numNum = ANum + BNum + 1;
        else numNum = ANum + BNum;
        if (numNum >= 10)
        {
            jinwei = true;
            numNum -= 10;
            num[i] = numNum;
        }
        else
        {
            jinwei = false;
            num[i] = numNum;
        }
        i++;
    }
    bool zero = true;
    for (int j = i; j >= 0; j--)
    {
        if (num[j] != 0) zero = false;
        if (!zero) cout << num[j];
    }
    return 0;
}