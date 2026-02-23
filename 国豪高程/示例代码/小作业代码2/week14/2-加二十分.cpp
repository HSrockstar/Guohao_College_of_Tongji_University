//#include <iostream>
//using namespace std;
//
///****************** TODO ******************/
//void add_score(int& score);
//void add_score(int* score);
//
//void add_score(int& score)
//{
//    score += 20;
//    if (score > 100)
//    {
//        score = 100;
//    }
//}
//
//void add_score(int* score)
//{
//    *score += 20;
//    if (*score > 100)
//    {
//        *score = 100;
//    }
//}
///**************** TODO-END ****************/
//
//int main()
//{
//    int score = 0;
//    cin >> score;
//
//    // 调用方法一
//    int tmp1 = score;
//    add_score(tmp1);
//    cout << "方法一得到结果：" << tmp1 << endl;
//
//    // 调用方法二
//    int tmp2 = score;
//    add_score(&tmp2);  // 思考：这个&是什么意思？
//    cout << "方法二得到结果：" << tmp2 << endl;
//
//    return 0;
//}