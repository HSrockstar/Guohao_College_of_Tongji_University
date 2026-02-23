#include <iostream>
using namespace std;

int balance = 100;

/****************** TODO ******************/
int sum = 100;
void save_money(int money)
{
    balance += money;
    cout << "存钱成功\n当前余额为" << balance << "元。" << endl;
}
void retrieve_money(int money)
{
    if (money <= balance)
    {
        balance -= money;
        cout << "取钱成功\n当前余额为" << balance << "元。" << endl;
    }
    else
    {
        cout << "余额不足\n当前余额为" << balance << "元。" << endl;
    }
}
void print_balance()
{
    cout << "当前余额为" << balance << "元。" << endl;
}
/**************** TODO-END ****************/

void atm_manager(int money)
{
    if (money > 0) {
        save_money(money);
    }
    else if (money < 0) {
        retrieve_money(-money);
    }
    print_balance();
}

int main()
{
    int query;

    cin >> query;
    while (query != 0)
    {
        atm_manager(query);
        cin >> query;
    }

    return 0;
}