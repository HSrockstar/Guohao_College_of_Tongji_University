#include <iostream>
#include <iomanip>
const int lightAmount = 100;
using namespace std;
bool isZhishu(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}
bool isHeshu(int n)
{
    if (n <= 1) return false;
    if (n == 2) return false;
    if (n % 2 == 0) return true;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0) return true;
    }
    return false;
}
bool isJishu(int n)
{
    if (n % 2 != 0) return true;
    else return false;
}
bool isOushu(int n)
{
    if (n % 2 == 0) return true;
    else return false;
}
int main()
{
    int light[lightAmount], lightCondition[lightAmount]{}, N;
    for (int i = 0; i < lightAmount; i++) light[i] = i;
    while (cin >> N && N != -1)
    {
        if (N == 1)
        {
            for (int i = 0; i < lightAmount; i++)
            {
                if (isZhishu(i) == true) lightCondition[i]++;
            }
        }
        if (N == 2)
        {
            for (int i = 0; i < lightAmount; i++)
            {
                if (isHeshu(i) == true) lightCondition[i]++;
            }
        }
        if (N == 3)
        {
            for (int i = 0; i < lightAmount; i++)
            {
                if (isJishu(i) == true) lightCondition[i]++;
            }
        }
        if (N == 4)
        {
            for (int i = 0; i < lightAmount; i++)
            {
                if (isOushu(i) == true) lightCondition[i]++;
            }
        }
    }
    cout << "Ï¨Ãð£º";
    for (int i = 0; i < lightAmount; i++)
    {
        if (lightCondition[i] % 3 == 0) cout << i << " ";
    }
    cout << endl << "³¤ÁÁ£º";
    for (int i = 0; i < lightAmount; i++)
    {
        if (lightCondition[i] % 3 == 1) cout << i << " ";
    }
    cout << endl << "ÉÁË¸£º";
    for (int i = 0; i < lightAmount; i++)
    {
        if (lightCondition[i] % 3 == 2) cout << i << " ";
    }
    return 0;
}