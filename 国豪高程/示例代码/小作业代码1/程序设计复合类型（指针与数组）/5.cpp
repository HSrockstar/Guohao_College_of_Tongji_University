#include <iostream>
#define MAX_STR_LENGTH 100
using namespace std;

void print_merged(const char(*str)[MAX_STR_LENGTH])
{
    /****************** TODO ******************/
    const char* p1 = str[0];
    const char* p2 = str[1];

    char word1[MAX_STR_LENGTH] = { 0 };
    char word2[MAX_STR_LENGTH] = { 0 };

    bool has_word1 = true;
    bool has_word2 = true;

    while (has_word1 || has_word2)
    {
        if (has_word1)
        {
            int idx = 0;
            while (*p1 == ' ' && *p1 != '\0') p1++;
            if (*p1 == '\0')
            {
                has_word1 = false;
            }
            else
            {
                while (*p1 != ' ' && *p1 != '\0')
                {
                    word1[idx++] = *p1++;
                }
                word1[idx] = '\0';
            }
        }

        if (has_word2)
        {
            int idx = 0;
            while (*p2 == ' ' && *p2 != '\0') p2++;
            if (*p2 == '\0')
            {
                has_word2 = false;
            }
            else
            {
                while (*p2 != ' ' && *p2 != '\0')
                {
                    word2[idx++] = *p2++;
                }
                word2[idx] = '\0';
            }
        }

        if (has_word1)
        {
            cout << word1;
            for (int i = 0; i < MAX_STR_LENGTH; i++) word1[i] = 0;
            if (has_word2 || (p1 < str[0] + MAX_STR_LENGTH && *(p1) != '\0'))
                cout << " ";
        }
        if (has_word2)
        {
            cout << word2;
            for (int i = 0; i < MAX_STR_LENGTH; i++) word2[i] = 0;
            if ((has_word1 && *(p1) != '\0') || (p2 < str[1] + MAX_STR_LENGTH && *(p2) != '\0'))
                cout << " ";
        }
    }
    /**************** TODO-END ****************/
}

int main()
{
    char str[2][MAX_STR_LENGTH] = {};

    cin.getline(str[0], MAX_STR_LENGTH);
    cin.getline(str[1], MAX_STR_LENGTH);

    print_merged(str);

    return 0;
}