#include <iostream>
using namespace std;

/****************** TODO ******************/
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**************** TODO-END ****************/

int main()
{
    int a = 0, b = 0;

    cin >> a >> b;

    swap(&a, &b);

    cout << a << " " << b << endl;

    return 0;
}