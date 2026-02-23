#include <iostream>
using namespace std;

/****************** TODO ******************/
int integer(double num)
{
    int a = static_cast<int>(num);
    return a;
}

double decimal(double num)
{
    int a = static_cast<int>(num);
    double b = num - a;
    return b;
}
/**************** TODO-END ****************/

int main()
{
    double num = 0;

    cin >> num;
    cout << "整数部分是" << integer(num)
        << "，小数部分是" << decimal(num) << "。" << endl;

    return 0;
}