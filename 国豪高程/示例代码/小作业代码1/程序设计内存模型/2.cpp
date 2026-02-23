#include <iostream>
using namespace std;

void atm(int money)
{
    /****************** TODO ******************/
    static int sum = 100;
    if (money < 0 && (-money) <= sum)
    {
        sum += money;
        cout << "取钱成功\n当前余额为" << sum << "元。" << endl;
    }
    else if (money < 0 && (-money) > sum)
    {
        cout << "余额不足\n当前余额为" << sum << "元。" << endl;
    }
    else if (money > 0)
    {
        sum += money;
        cout << "存钱成功\n当前余额为" << sum << "元。" << endl;
    }
    /**************** TODO-END ****************/
}

int main()
{
    int query;

    cin >> query;
    while (query != 0)
    {
        atm(query);
        cin >> query;
    }

    return 0;
}