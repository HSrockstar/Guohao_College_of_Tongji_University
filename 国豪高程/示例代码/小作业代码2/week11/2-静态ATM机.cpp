//#include <iostream>
//using namespace std;
//
//void atm(int money)
//{
//    /****************** TODO ******************/
//    static int account_balance = 100;
//    if (money > 0)
//    {
//        account_balance += money;
//        cout << "存钱成功" << endl;
//        cout << "当前余额为" << account_balance << "元。" << endl;
//    }
//
//    else if (money < 0)
//    {
//        if (account_balance + money < 0)
//        {
//            cout << "余额不足" << endl;
//            cout << "当前余额为" << account_balance << "元。" << endl;
//        }
//
//        else if (account_balance + money >= 0)
//        {
//            account_balance += money;
//            cout << "取钱成功" << endl;
//            cout << "当前余额为" << account_balance << "元。" << endl;
//        }
//    }
//
//    /**************** TODO-END ****************/
//}
//
//int main()
//{
//    int query;
//
//    cin >> query;
//    while (query != 0)
//    {
//        atm(query);
//        cin >> query;
//    }
//
//    return 0;
//}