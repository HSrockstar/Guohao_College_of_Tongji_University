#include <iostream>
#include <cstring>
using namespace std;

bool isBiaodian(char ch)
{
    return ch == ',' || ch == '.' || ch == '!' || ch == '?' || ch == '\"';
}
bool isSpace(char ch)
{
    return ch == ' ';
}
bool isWord(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == '\'') || (ch == '-');
}

int main()
{
    char str[200] = {}, temp1[200] = {}, temp2[200] = {}, strNew[200] = {};
    cin.getline(str, 200);
    int s = 0, sn = 0;
    size_t len_str = strlen(str);

    while (s < len_str)
    {
        // 跳过前置空格
        while (s < len_str && isSpace(str[s]))
        {
            s++;
        }
        if (s >= len_str) break;

        // 提取基准单词
        int t1 = 0;
        int word_start = s;
        while (s < len_str && isWord(str[s]))
        {
            temp1[t1++] = str[s++];
        }
        temp1[t1] = '\0';

        // 处理纯标点
        if (t1 == 0)
        {
            if (isBiaodian(str[s]))
            {
                // 删除可能的多余空格
                if (sn > 0 && isSpace(strNew[sn - 1]))
                {
                    sn--;
                }
                strNew[sn++] = str[s++];
                // 标点后空格处理
                bool has_space = false;
                while (s < len_str && isSpace(str[s]))
                {
                    has_space = true;
                    s++;
                }
                if (has_space && s < len_str)
                {
                    strNew[sn++] = ' ';
                }
            }
            else
            {
                s++;
            }
            continue;
        }

        // 写入基准单词
        for (int i = word_start; i < s; i++)
        {
            strNew[sn++] = str[i];
        }

        // 写入单词后的标点，句尾标点处理
        bool after_biaodian_space = false;
        while (s < len_str && isBiaodian(str[s]))
        {
            // 写入标点前删除可能的多余空格
            if (sn > 0 && isSpace(strNew[sn - 1]))
            {
                sn--;
            }
            strNew[sn++] = str[s++];
            // 标点后空格处理（非句尾）
            while (s < len_str && isSpace(str[s]))
            {
                after_biaodian_space = true;
                s++;
            }
        }

        // 处理单词后的空格
        bool need_space = after_biaodian_space;
        if (!need_space)
        {
            while (s < len_str && isSpace(str[s]))
            {
                need_space = true;
                s++;
            }
        }

        // 检测并跳过重复单词
        bool has_dieci;
        do
        {
            has_dieci = false;
            if (s >= len_str) break;

            int t2 = 0;
            int next_word_start = s;
            while (s < len_str && isWord(str[s]))
            {
                temp2[t2++] = str[s++];
            }
            temp2[t2] = '\0';

            if (t2 == 0) break;

            if (strcmp(temp1, temp2) == 0)
            {
                has_dieci = true;
                while (s < len_str && isSpace(str[s]))
                {
                    s++;
                }
            }
            else {
                s = next_word_start;
                if (need_space)
                {
                    strNew[sn++] = ' ';
                    need_space = false;
                }
                while (s < len_str && isSpace(str[s]))
                {
                    s++;
                }
            }
        } while (has_dieci);

        if (!has_dieci && need_space && s < len_str)
        {
            strNew[sn++] = ' ';
        }
    }

    // 清理末尾多余空格
    while (sn > 0 && isSpace(strNew[sn - 1]))
    {
        sn--;
    }
    strNew[sn] = '\0';
    cout << strNew;

    return 0;
}
