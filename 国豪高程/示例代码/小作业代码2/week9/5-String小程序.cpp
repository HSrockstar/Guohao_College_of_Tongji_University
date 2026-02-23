//#include <iostream>
//#include <string>
//using namespace std;
//
//void Length(string str);
//void Output(string str);
//string Trans(string str);
//string Input(string str);
//string Replace(string str);
//
//string str;
//
//int main()
//{
//    char choice;
//    while (true)
//    {
//        cin >> choice;
//        if (choice == 'q')
//        {
//            Output(str);
//            break;
//        }
//        switch (choice)
//        {
//        case '1':
//            Length(str);
//            break;
//        case '2':
//            Output(str);
//            break;
//        case '3':
//            str = Trans(str);
//            break;
//        case '4':
//            str = Input(str);
//            break;
//        case '5':
//            str = Replace(str);
//            break;
//        }
//    }
//    return 0;
//}
//
//void Length(string str)
//{
//    cout << str.size() << endl;
//}
//
//void Output(string str)
//{
//    if (str.size() != 0)
//        cout << str << endl;
//}
//
//string Trans(string str)
//{
//    char option;
//    cin >> option;
//    if (option == 'U')
//    {
//        for (int i = static_cast<int>(str.size() - 1); i >= 0; i--)
//        {
//            char ch = str[i];
//            if (ch >= 97 && ch <= 122)
//            {
//                ch = ch - 32;
//            }
//            str[i] = ch;
//        }
//    }
//
//    else if (option == 'L')
//    {
//        for (int i = static_cast<int>(str.size() - 1); i >= 0; i--)
//        {
//            char ch = str[i];
//            if (ch >= 65 && ch <= 90)
//            {
//                ch = ch + 32;
//            }
//            str[i] = ch;
//        }
//    }
//    return str;
//}
//
//string Input(string str)
//{
//    string temp;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    getline(cin, temp);
//    int position;
//    cin >> position;
//    str.insert(position, temp);
//    return str;
//}
//
//string Replace(string str)
//{
//    string target;
//    string replace;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    getline(cin, target);
//    getline(cin, replace);
//
//    size_t pos = str.find(target);
//    if (pos != string::npos)
//    {
//        str.replace(pos, target.size(), replace);
//    }
//    return str;
//}