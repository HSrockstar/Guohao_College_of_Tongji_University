//#include <iostream>
//using namespace std;
//
///****************** TODO ******************/
//bool pass(char grade);
//bool pass(int grade);
//bool pass(double grade);
//
//bool pass(char grade)
//{
//    if (grade == 'F')
//        return false;
//    else
//        return true;
//}
//
//bool pass(int grade)
//{
//    if (grade < 60)
//        return false;
//    else
//        return true;
//}
//
//bool pass(double grade)
//{
//    if (grade < 2.00)
//        return false;
//    else
//        return true;
//}
///**************** TODO-END ****************/
//
//// 下面是一个使用你所编写函数的样例程序
//int main()
//{
//    // 三种情况分别测试
//    char grade = '\0';
//    int score_100 = 0;
//    double score_5 = 0;
//
//    cin >> grade >> score_100 >> score_5;
//
//    cout << "成绩：" << grade << " 及格情况："
//        << (pass(grade) ? "及格" : "不及格") << endl;
//
//    cout << "成绩：" << score_100 << " 及格情况："
//        << (pass(score_100) ? "及格" : "不及格") << endl;
//
//    cout << "成绩：" << score_5 << " 及格情况："
//        << (pass(score_5) ? "及格" : "不及格") << endl;
//
//    return 0;
//}