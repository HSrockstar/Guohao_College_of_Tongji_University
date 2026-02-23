#include <iostream>
#define BLOCK_NUM 200 // 盘块数量
#define INSTR_LENGTH 100 // 指令最大长度
using namespace std;

int memory[BLOCK_NUM] = {};  // 模拟内存

/****************** TODO ******************/
bool check_memory[BLOCK_NUM] = {};

bool BlockManager(char instr[INSTR_LENGTH]) {
    char trans_str[10] = { 0,0,0,0,0,0,0,0,0,0 };
    int x, n, num;
    sscanf_s(instr, "%s", trans_str, (unsigned)_countof(trans_str));

    if (strcmp(trans_str, "new") == 0)
    {
        sscanf_s(instr, "%s %d %d", trans_str, (unsigned)_countof(trans_str), &x, &n);

        if (x < 0 || x >= BLOCK_NUM || x + n > BLOCK_NUM)
        {
            cout << "失败" << endl;
            return true;
        }

        bool check_new = true;
        for (int i = x; i < x + n; ++i)
        {
            if (check_memory[i])
            {
                check_new = false;
                break;
            }
        }

        if (check_new)
        {
            for (int i = x; i < x + n; ++i)
            {
                check_memory[i] = true;
            }
            cout << "成功" << endl;
        }
        else
        {
            cout << "失败" << endl;
        }
    }

    else if (strcmp(trans_str, "free") == 0)
    {
        sscanf_s(instr, "%s %d %d", trans_str, (unsigned)_countof(trans_str), &x, &n);

        if (x < 0 || x >= BLOCK_NUM || x + n > BLOCK_NUM)
        {
            cout << "失败" << endl;
            return true;
        }

        bool check_free = true;

        for (int i = x; i < x + n; ++i)
        {
            if (!check_memory[i])
            {
                check_free = false;
                break;
            }
        }

        if (check_free)
        {
            for (int i = x; i < x + n; ++i)
            {
                check_memory[i] = false;
            }
            cout << "成功" << endl;
        }

        else
        {
            cout << "失败" << endl;
        }
    }

    else if (strcmp(trans_str, "read") == 0)
    {
        sscanf_s(instr, "%s %d", trans_str, (unsigned)_countof(trans_str), &x);

        if (x < 0 || x >= BLOCK_NUM || !check_memory[x])
        {
            cout << "失败" << endl;
        }
        else
        {
            cout << "成功 " << memory[x] << endl;
        }
    }

    else if (strcmp(trans_str, "write") == 0)
    {
        sscanf_s(instr, "%s %d %d", trans_str, (unsigned)_countof(trans_str), &x, &num);

        if (x < 0 || x >= BLOCK_NUM || !check_memory[x])
        {
            cout << "失败" << endl;
        }

        else
        {
            memory[x] = num;
            cout << "成功" << endl;
        }
    }

    else if (strcmp(trans_str, "q") == 0)
    {
        return false;
    }

    else
    {
        cout << "失败" << endl;
    }
    return true;
}
/**************** TODO-END ****************/

int main() {
    char instr[INSTR_LENGTH] = {}; // 输入的指令
    cin.getline(instr, INSTR_LENGTH);

    while (BlockManager(instr)) {
        cin.getline(instr, INSTR_LENGTH);
    }

    return 0;
}