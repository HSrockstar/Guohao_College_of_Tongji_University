#include <iostream>
#define ARRAY_LENGTH 20
using namespace std;

char array3[ARRAY_LENGTH];
/****************** TODO ******************/
void print_array_ascii(char arr[])
{
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        cout << int(arr[i]) << " ";
    }
    cout << endl;
}
/**************** TODO-END ****************/

int main()
{
    char array1[ARRAY_LENGTH];
    static char array2[ARRAY_LENGTH];

    cout << "未初始化的三个结果：" << endl;
    cout << "1. 自动变量数组array1" << endl;
    print_array_ascii(array1);
    cout << "2. 静态变量数组array2" << endl;
    print_array_ascii(array2);
    cout << "3. 全局变量数组array3" << endl;
    print_array_ascii(array3);

    cin.getline(array1, ARRAY_LENGTH);
    cin.getline(array2, ARRAY_LENGTH);
    cin.getline(array3, ARRAY_LENGTH);

    cout << "输入后的三个结果：" << endl;
    cout << "1. 自动变量数组array1" << endl;
    print_array_ascii(array1);
    cout << "2. 静态变量数组array2" << endl;
    print_array_ascii(array2);
    cout << "3. 全局变量数组array3" << endl;
    print_array_ascii(array3);

    return 0;
}