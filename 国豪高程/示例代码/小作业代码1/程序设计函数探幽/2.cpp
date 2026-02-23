#include <iostream>
using namespace std;

/****************** TODO ******************/
long long f[91];
long long fibonacci(int num)
{
    f[1] = 1;
    f[2] = 1;
    if (num == 1 || num == 2);
    else
    {
        for (int i = 3; i <= num; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
    }
    return f[num];
}
/**************** TODO-END ****************/

int main()
{
    int num = 0; // 斐波那契数列的项数

    cin >> num;
    cout << "斐波那契数列中第" << num
        << "项的值为" << fibonacci(num) << "。" << endl;

    return 0;
}