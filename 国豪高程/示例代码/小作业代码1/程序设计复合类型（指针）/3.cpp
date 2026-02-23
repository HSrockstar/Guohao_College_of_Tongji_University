#include <iostream>
#define ARRAY_LENGTH 50
using namespace std;

void decode(char* p)
{
    /****************** TODO ******************/
    size_t len = strlen(p);
    char newp[ARRAY_LENGTH + 1] = {};
    newp[len] = '\0';
    int i = 0, j = 0;
    while (j < len)
    {
        newp[j] = p[i];
        newp[j + 1] = p[len - 1 - i];
        j += 2;
        i++;
    }
    for (int i = 0; i < len; i++)
    {
        cout << newp[i];
    }
    /**************** TODO-END ****************/
}

int main()
{
    char str[ARRAY_LENGTH] = {};
    cin.getline(str, ARRAY_LENGTH);

    decode(str);

    return 0;
}