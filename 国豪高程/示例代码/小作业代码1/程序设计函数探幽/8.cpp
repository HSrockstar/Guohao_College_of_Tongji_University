#include <iostream>
#include <iomanip>
#define ARRAY_MAX_LENGTH 200
using namespace std;

/****************** TODO ******************/
void strip_space(char str[])
{
    size_t len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            for (int j = i; j < len - 1; j++)
                str[j] = str[j + 1];
            str[len - 1] = '\0';
        }
    }
}
double calculate(char oper, double answer, int operand)
{
    if (answer == 0 && oper != '+') answer = operand;
    switch (oper)
    {
    case '+':
        answer += operand;
        break;
    case '*':
        answer *= operand;
        break;
    case '/':
        if (operand == 0)
        {
            cout << "除数不能为零";
            exit(0);
        }
        else answer /= operand;
        break;
    case '-':
        answer -= operand;
        break;
    }
    return answer;
}
/**************** TODO-END ****************/

int main()
{
    char expression[ARRAY_MAX_LENGTH] = {};

    cout << fixed << setprecision(6);
    cin.getline(expression, ARRAY_MAX_LENGTH);
    strip_space(expression);  // 删除表达式中的空格
    double answer = 0;
    int operand = 0;    // 操作数
    char oper = '\0';   // 运算符
    for (int i = 0; expression[i] != '\0'; ++i)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            // 如果是数字，保存继续读取
            operand *= 10;
            operand += expression[i] - '0';
        }
        else
        {
            // 如果是四则运算符，则计算前面的表达式
            answer = calculate(oper, answer, operand);
            operand = 0;
            oper = expression[i];

            cout << answer << endl;
        }
        // 本题规定无非法字符和不合规输入
    }

    // 计算最后一个表达式
    answer = calculate(oper, answer, operand);
    cout << answer << endl;

    return 0;
}