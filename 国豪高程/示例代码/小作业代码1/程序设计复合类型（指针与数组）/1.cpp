#include <iostream>
using namespace std;

char* my_strcat(char* dest, const char* src)
{
    /****************** TODO ******************/
    // 思考：<string.h>头文件中的strcat为什么返回类型为char*？
    char* dest_start = dest;
    while (*dest != '\0') dest++;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest_start;
    /**************** TODO-END ****************/
}

int main()
{
    const int str_length = 100;

    char arr1[str_length] = {};
    char arr2[str_length] = {};

    cin.getline(arr1, str_length);
    cin.getline(arr2, str_length);

    my_strcat(arr1, arr2);

    cout << arr1 << endl;

    return 0;
}