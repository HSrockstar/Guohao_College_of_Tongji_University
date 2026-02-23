#include <iostream>
using namespace std;

int main() {
    int array[5] = { 0 };
    cout << "请输入五个整数（用空格分隔）：" << endl;
    for (int i = 0; i < 5; ++i)
    {
        cin >> array[i];
    }

    cout << "数组中每个字节的十进制值为：" << endl;

    for (int i = 0; i < 5; ++i)
    {
        // 使用指针访问每个字节
        signed char* bytePointer = reinterpret_cast<signed char*>(&array[i]);

        // 按字节顺序输出每个字节的十进制值
        for (int j = 0; j < sizeof(int); ++j)
        {
            cout << static_cast<int>(bytePointer[j]) << " ";
        }
    }

    cout << endl; // 输出换行符
    return 0;
}