//#include <iostream>
//#define STRING_MAX_LENGTH 200
//using namespace std;
//
///****************** TODO ******************/
//int to_upper(char str[STRING_MAX_LENGTH]);
//
//int to_upper(char str[STRING_MAX_LENGTH])
//{
//    int count = 0;
//
//    for (int i = 0; i < 200; i++)
//    {
//        char ch = str[i];
//        if (ch >= 97 && ch <= 122)
//        {
//            ch = ch - 32;
//            count++;
//        }
//        else if (ch == '\0')//防止访问到未初始化的内存
//        {
//            break;
//        }
//        str[i] = ch;
//    }
//    return count;
//}
//
///**************** TODO-END ****************/
//
//int main()
//{
//    char str[STRING_MAX_LENGTH];
//    cin.getline(str, STRING_MAX_LENGTH);
//
//    int num = to_upper(str);
//    // 想一想，字符串内容改变了吗？为什么？
//
//    cout << "共转换" << num << "个字母。" << endl;
//    cout << str << endl;
//
//    return 0;
//}