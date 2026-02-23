#include<iostream>
#include<string>
using namespace std;

string num1;
string num2;

int main()
{
    //输入部分
    cout << "请输入两个数字，每个一行：" << endl;
    getline(cin, num1);
    getline(cin, num2);
    int len1 = static_cast<int>(num1.size());
    int len2 = static_cast<int>(num2.size());

    //在前面补零使两个数字长度相等且第一位是零
    if (len1 > len2)
    {
        for (int i = 0; i <= (len1 - len2); i++)
        {
            num2 = "0" + num2;
        }
        num1 = "0" + num1;
    }

    else if (len1 < len2)
    {
        for (int i = 0; i <= (len2 - len1); i++)
        {
            num1 = "0" + num1;
        }
        num2 = "0" + num2;
    }

    else
    {
        num1 = "0" + num1;
        num2 = "0" + num2;
    }

    //进行计算
    int length = static_cast<int>(num1.size());
    string result(length, '0');//设定result的长度，避免溢出
    int temp = 0;//使用temp实现进位功能
    for (int i = length - 1; i >= 0; i--)
    {
        int number1 = static_cast<int>(num1[i] - '0');
        int number2 = static_cast<int>(num2[i] - '0');
        //-'0'保证最后输出的是相应的整数值
        int sum = number1 + number2 + temp;
        if (sum < 10)//直接结算
        {
            result[i] = static_cast<char>(sum + '0');
            temp = 0;
        }
        else//余数结算，商放到前一位
        {
            temp = sum / 10;
            sum = sum % 10;
            result[i] = static_cast<char>(sum + '0');
        }
    }

    //输出结果，如第一位是0，则从第二位开始输出
    if (result[0] == '0')
    {
        for (int i = 1; i < length; i++)
        {
            cout << result[i];
        }
        cout << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}