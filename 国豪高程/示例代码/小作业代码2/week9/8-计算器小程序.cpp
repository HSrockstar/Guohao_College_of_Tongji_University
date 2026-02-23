//#include <iostream>
//#include <iomanip>
//#define ARRAY_MAX_LENGTH 200
//using namespace std;
//
///****************** TODO ******************/
//void strip_space(char expression[ARRAY_MAX_LENGTH]);
//double calculate(char oper, double answer, int operand);
//
//void strip_space(char expression[ARRAY_MAX_LENGTH])
//{
//    int count = 0;
//    char temp[ARRAY_MAX_LENGTH] = {};
//
//    for (int i = 0; i < strlen(expression); i++)
//    {
//        if (expression[i] == ' ')
//        {
//            continue;
//        }
//
//        else if (expression[i] != ' ')
//        {
//            temp[count] = expression[i];
//            count++;
//        }
//    }
//
//    for (int i = 0; i < ARRAY_MAX_LENGTH; i++)
//    {
//        if (i < strlen(temp))
//        {
//            expression[i] = temp[i];
//        }
//        else
//        {
//            expression[i] = '\0';
//        }
//    }
//}
//
//double calculate(char oper, double answer, int operand)
//{
//    switch (oper)
//    {
//    case '\0':
//        answer = static_cast<double>(operand);
//        break;
//    case  '+':
//        answer = answer + operand;
//        break;
//    case  '-':
//        answer = answer - operand;
//        break;
//    case  '*':
//        answer = answer * operand;
//        break;
//    case  '/':
//        if (operand != 0)
//        {
//            answer = answer / operand;
//        }
//        else
//        {
//            cout << "除数不能为零" << endl;
//            exit(0);
//        }
//        break;
//    }
//    return answer;
//}
///**************** TODO-END ****************/
//
//int main()
//{
//    char expression[ARRAY_MAX_LENGTH] = {};
//
//    cout << fixed << setprecision(6);
//    cin.getline(expression, ARRAY_MAX_LENGTH);
//    strip_space(expression);  // 删除表达式中的空格
//
//    double answer = 0;
//    int operand = 0;    // 操作数
//    char oper = '\0';   // 运算符
//    for (int i = 0; expression[i] != '\0'; ++i)
//    {
//        if (expression[i] >= '0' && expression[i] <= '9')
//        {
//            // 如果是数字，保存继续读取
//            operand *= 10;
//            operand += expression[i] - '0';
//        }
//        else
//        {
//            // 如果是四则运算符，则计算前面的表达式
//            answer = calculate(oper, answer, operand);
//            operand = 0;
//            oper = expression[i];
//
//            cout << answer << endl;
//        }
//        // 本题规定无非法字符和不合规输入
//    }
//
//    // 计算最后一个表达式
//    answer = calculate(oper, answer, operand);
//    cout << answer << endl;
//
//    return 0;
//}