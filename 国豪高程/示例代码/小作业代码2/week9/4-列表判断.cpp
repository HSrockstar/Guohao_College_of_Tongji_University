//#include <iostream>
//#include <string>
//using namespace std;
//
//bool Check_Integer(const string& str, int& start, int& end);// 判断合法整数
//bool Check_List(const string& str, int& start, int& end);// 判断合法列表
//
//int main() 
//{
//    string input;
//    getline(cin, input);
//    int start = 0, end = 0;
//    if (Check_List(input,start,end) && end == input.size())
//    {
//        cout << "格式合法！" << endl;
//    }
//    else 
//    {
//        cout << "格式非法！" << endl;
//    }
//
//    return 0;
//}
//
//
//bool Check_Integer(const string& str, int& start, int& end)
//{
//    int n = static_cast<int>(str.size());
//    // 跳过空格
//    while (start < n && str[start] == ' ')
//    {
//        start++;
//    }
//    // 检查符号
//    bool check_sign = (start < n && (str[start] == '+' || str[start] == '-'));
//    if (check_sign)
//    {
//        start++;
//    }
//    // 检查数字
//    if (start == n || !(str[start] >= '0' && str[start] <= '9'))
//    {
//        return false;
//    }
//    while (start < n && (str[start] >= '0' && str[start] <= '9'))
//    {
//        start++;
//    }
//    // 记录结束位置
//    end = start;
//    return true;
//}
//
//
//bool Check_List(const string& str, int& start, int& end)
//{
//    int n = static_cast<int>(str.size());
//    // 跳过前导空格
//    while (start < n && (str[start] == ' ')) 
//    {
//        start++;
//    }
//    // 检查[开头
//    if (start == n || str[start] != '[')
//    {
//        return false;
//    }
//    start++; 
//    // 跳过[
//    
//    int comma_count = 0;// 逗号数量
//    bool check_element = false; // 标记是否至少有一个元素
//    while (start < n) 
//    {
//        // 跳过空格
//        while (start < n && (str[start] == ' '))
//        {
//            start++;
//        }
//        if (start == n)
//        {
//            break;
//        }
//        if (str[start] == ']')
//        {
//            start++; // 跳过]
//            break;
//        }
//        int nextEnd;
//        // 判断当前元素是否是整数
//        if (Check_Integer(str, start, nextEnd))
//        {
//            check_element = true;
//            start = nextEnd;
//        }
//        // 判断当前元素是否是列表
//        else if (Check_List(str, start, nextEnd))
//        {
//            check_element = true;
//            start = nextEnd;
//        }
//        // 不是整数也不是列表，也就是非法
//        else 
//        {
//            return false; 
//        }
//        // 跳过空格
//        while (start < n && str[start] == ' ')
//        {
//            start++;
//        }
//        if (start < n && str[start] == ',')
//        {
//            comma_count++;
//            start++; // 跳过逗号
//        }
//    }
//    // 检查是否有非法逗号
//    if (comma_count > 0 && !check_element)
//    {
//        return false;
//    }
//    // 记录结束位置
//    end = start;
//    return true;
//}
//
