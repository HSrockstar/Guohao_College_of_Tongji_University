#include <iostream>
#include <string>
using namespace std;
int main()
{
    int num;
    while (true)
    {
        cin >> num;
        if (cin.good())
        {
            cout << num << endl;
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "ÊäÈë´íÎó£¡" << endl;
        }
    }
    return 0;

}