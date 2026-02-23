#include <iostream>
#include <cstring>
using namespace std;
char lujing[200] = { "C:\\Users\\Student" };
char saveList[200][200]{};
char input[200]{};
int main()
{

    int row = 0;//saveList行数
    size_t size = strlen(lujing);
    int len = static_cast<int>(size);
    for (int i = 0; i < len; i++)//存入saveList
    {
        saveList[row][i] = lujing[i];
    }
    row++;
    while (true)
    {
        cin.getline(input, 200);
        if (strcmp(input, "quit") != 0)
        {
            bool panduan = true;//判断后面是否还有'\'
            int index = 3;
            while (panduan)
            {
                bool notSave = false;//若在同一个cd内则不存入saveList
                size_t size = strlen(lujing);
                int len = static_cast<int>(size);
                if (input[index] == '.' && input[index + 1] == '.')//cd ..返回上一级
                {
                    index += 3;//跳过当前操作
                    if (input[index - 1] == '\\')
                    {
                        panduan = true;//判断是否还有后续操作
                        notSave = true;
                    }
                    else panduan = false;
                    for (int i = len; i >= 0; i--)
                    {
                        if (lujing[i] == '\\' && lujing[i - 1] != ':')//持续删除直到遇到‘\’
                        {
                            lujing[i] = '\0';
                            break;
                        }
                        else if (lujing[i - 1] == ':')//根目录不变
                        {
                            break;
                        }
                        else lujing[i] = '\0';
                    }
                    size_t size = strlen(lujing);
                    int len = static_cast<int>(size);
                    if (notSave == false)
                    {
                        for (int i = 0; i < len; i++)//存入saveList
                        {
                            saveList[row][i] = lujing[i];
                        }
                        row++;
                        saveList[row][len] = '\0';
                    }
                }
                else if (input[index] == '.' && input[index + 1] != '.')//cd .当前路径不变
                {
                    index += 2;//跳过当前操作
                    if (input[index - 1] == '\\')
                    {
                        panduan = true;//判断是否还有后续操作
                        notSave = true;
                    }
                    else panduan = false;
                    size_t size = strlen(lujing);
                    int len = static_cast<int>(size);
                    if (notSave == false)
                    {
                        for (int i = 0; i < len; i++)//存入saveList
                        {
                            saveList[row][i] = lujing[i];
                        }
                        row++;
                        saveList[row][len] = '\0';
                    }
                }
                else if (input[index] != '.') //cd xxx下一级路径
                {
                    if (len != 3) lujing[len] = '\\';
                    int newLen = 0;
                    for (int i = index; (input[i] != '\0' && input[i] != '\\'); i++)//计算新路径长度
                    {
                        newLen++;
                    }
                    int j = index;
                    if (len == 3) len--;
                    for (int i = len + 1; i < len + 1 + newLen; i++)//将后续路径接在后面
                    {
                        lujing[i] = input[index];
                        index++;
                    }
                    index++;//跳过当前操作
                    if (input[index - 1] == '\\')
                    {
                        panduan = true;//判断是否还有后续操作
                        notSave = true;
                    }
                    else panduan = false;
                    lujing[len + 1 + newLen] = '\0';
                    size_t size = strlen(lujing);
                    int len = static_cast<int>(size);
                    if (notSave == false)
                    {
                        for (int i = 0; i < len; i++)//存入saveList
                        {
                            saveList[row][i] = lujing[i];
                        }
                        row++;
                        saveList[row][len] = '\0';
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < row; i++)
    {
        cout << saveList[i] << endl;
    }
    return 0;
}
