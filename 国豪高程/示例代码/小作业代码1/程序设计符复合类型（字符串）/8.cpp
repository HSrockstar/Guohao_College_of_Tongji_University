#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char input[201];
    char compressed[401];
    int inputLen, compLen = 0;
    cin.getline(input, 201);
    size_t size = strlen(input);
    inputLen = static_cast<int>(size);
    char current = input[0];
    int count = 1;

    if (inputLen == 0) cout << "压缩失败！" << endl;
    // 进行压缩
    for (int i = 1; i < inputLen; i++) {
        if (input[i] == current) {
            count++;
            // 重置计数
            if (count == 9) {
                compressed[compLen++] = current;
                compressed[compLen++] = '0' + count;  // 数字转字符
                count = 0;
            }
        }
        else {
            // 压缩前一组字符
            compressed[compLen++] = current;
            compressed[compLen++] = '0' + count;
            // 切换到新字符
            current = input[i];
            count = 1;
        }
    }

    // 处理最后一组未压缩的字符
    if (count > 0) {
        compressed[compLen++] = current;
        compressed[compLen++] = '0' + count;
    }
    compressed[compLen] = '\0';  // 压缩字符串添加结束符

    // 判断压缩是否有效
    if (compLen < inputLen) {
        cout << compressed << endl;
    }
    else {
        cout << "压缩失败！" << endl;
    }

    return 0;
}