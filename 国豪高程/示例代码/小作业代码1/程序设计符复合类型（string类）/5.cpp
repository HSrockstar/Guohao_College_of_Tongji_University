#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "", strList[200], zichuan;
    int listIndex = 0;
    char num;
    while (cin >> num && num != 'q')
    {
        size_t length = str.size();
        int len = static_cast<int>(length);
        switch (num)
        {
            // 长度获取
        case '1':
            strList[listIndex++] = to_string(len);
            break;

            // 字符串输出
        case '2':
            if (str != "")
            {
                strList[listIndex++] = str;
            }
            break;

            // 大小写翻转
        case '3':
            cin >> num;
            switch (num)
            {
            case 'L':
                for (int i = 0; i < len; i++)
                {
                    if (str[i] >= 'A' && str[i] <= 'Z')
                    {
                        str[i] = str[i] + ('a' - 'A');
                    }
                }
                break;
            case 'U':
                for (int i = 0; i < len; i++)
                {
                    if (str[i] >= 'a' && str[i] <= 'z')
                    {
                        str[i] = str[i] - ('a' - 'A');
                    }
                }
                break;
            }
            break;

            // 定点插入
        case '4':
            int position;
            cin >> zichuan >> position;
            str.insert(position, zichuan);
            break;

            // 子串替换
        case '5':
            string s1, s2;
            cin >> s1 >> s2;
            size_t pos = str.find(s1);
            if (pos != string::npos)// string::npos是未找到返回的一个特殊值
            {
                str.replace(pos, s1.size(), s2);
            }
            break;
        }
    }
    for (int i = 0; i < listIndex; i++) cout << strList[i] << endl;
    cout << str;
    return 0;
}