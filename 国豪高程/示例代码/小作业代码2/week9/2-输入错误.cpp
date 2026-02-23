//#include <iostream>
//#include <string>
//#include <limits>
//using namespace std;
//
//string str;
//bool a = true;
//
//int main()
//{
//    while (a)
//    {
//        getline(cin, str);
//        int length = static_cast<int>(str.size());
//
//        if (length > 1)
//        {
//            for (int i = 0; i < length; i++)
//            {
//                if (((str[i] > 47 && str[i] < 58) || str[i] == 45) && i == 0)
//                    continue;
//
//                else if (str[i] > 47 && str[i] < 58 && i>0 && i < length - 1)
//                    continue;
//
//                else if (str[i] > 47 && str[i] < 58 && i == length - 1)
//                    a = false;
//
//                else
//                {
//                    cout << "ÊäÈë´íÎó£¡" << endl;
//                    cin.clear();
//                    break;
//                }
//            }
//        }
//
//        else
//        {
//            if ((str[0] > 47 && str[0] < 58) || str[0] == 45)
//                a = false;
//
//            else
//            {
//                cout << "ÊäÈë´íÎó£¡" << endl;
//                cin.clear();
//            }
//        }
//    }
//    cout << str;
//    return 0;
//}