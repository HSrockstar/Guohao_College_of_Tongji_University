//#include <iostream>
//#define MAX_STR_LENGTH 100
//using namespace std;
//
//void print_merged(const char(*str)[MAX_STR_LENGTH])
//{
//    /****************** TODO ******************/
//    bool a = true;
//    int sign = 0;
//    int i = 0;
//    int j = 0;
//    while (a)
//    {
//        if (sign % 2 == 0)
//        {
//            while (true)
//            {
//                if (str[0][i] == ' ')
//                {
//                    cout << str[0][i];
//                    sign++;
//                    i++;
//                    break;
//                }
//                else if (str[0][i] == '\0')
//                {
//                    a = false;
//                    cout << " " << *str + MAX_STR_LENGTH + j << endl;
//                    break;
//                }
//                else
//                {
//                    cout << str[0][i];
//                    i++;
//                }
//            }
//        }
//
//        else if (sign % 2 == 1)
//        {
//            while (true)
//            {
//                if (str[1][j] == ' ')
//                {
//                    cout << str[1][j];
//                    sign++;
//                    j++;
//                    break;
//                }
//                else if (str[1][j] == '\0')
//                {
//                    a = false;
//                    cout << " " << *str + i << endl;
//                    break;
//                }
//                else
//                {
//                    cout << str[1][j];
//                    j++;
//                }
//            }
//        }
//    }
//
//    /**************** TODO-END ****************/
//}
//
//int main()
//{
//    char str[2][MAX_STR_LENGTH] = {};
//
//    cin.getline(str[0], MAX_STR_LENGTH);
//    cin.getline(str[1], MAX_STR_LENGTH);
//
//    print_merged(str);
//
//    return 0;
//}