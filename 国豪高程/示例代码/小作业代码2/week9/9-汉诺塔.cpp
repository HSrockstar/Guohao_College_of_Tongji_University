//#include <iostream>
//using namespace std;
//
//void hanoitower(char start, char trans, char end, int count);
//int num = 0;
//
//int main()
//{
//    char start;
//    char trans;
//    char end;
//    int count;
//    cin >> start >> end >> count;
//    trans = 'A' + 'B' + 'C' - start - end;
//    hanoitower(start, trans, end, count);
//    return 0;
//}
//
//void hanoitower(char start, char trans, char end, int count)
//{
//    if (count == 1)
//    {
//        num++;
//        cout << num << ". " << start << " -> " << end << endl;
//    }
//    else
//    {
//        count--;
//        hanoitower(start, end, trans, count);
//        num++;
//        cout << num << ". " << start << " -> " << end << endl;
//        hanoitower(trans, start, end, count);
//    }
//}