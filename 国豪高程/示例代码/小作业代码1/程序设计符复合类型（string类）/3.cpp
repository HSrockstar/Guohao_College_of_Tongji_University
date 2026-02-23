#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str, temp;
    while (getline(cin, temp))
    {
        if (temp == " ") break;
        str += temp;
    }
    cout << str.size() << endl << str;;
    return 0;

}