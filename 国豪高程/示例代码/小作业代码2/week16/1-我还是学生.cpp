//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//class StudentInfo {
//    /****************** TODO ******************/
//private:
//    char name[20] = {}; // 学生姓名
//    char major[40] = {}; // 专业
//    int year = 0; // 入学年份
//    double score = 0.0; // 平均绩点
//    /**************** TODO-END ****************/
//public:
//    void inputStudentInfo();
//    void printStudentInfo();
//};
//
///****************** TODO ******************/
//void StudentInfo::inputStudentInfo()
//{
//    cin.getline(name, 20);
//    cin.getline(major, 40);
//    cin >> year;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    cin >> score;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//}
//
//void StudentInfo::printStudentInfo()
//{
//    cout << "姓名：" << name << endl;
//    cout << "专业：" << major << endl;
//    cout << "入学年份：" << year << endl;
//    cout << "平均绩点：" << fixed << setprecision(2) << score << endl;
//}
//
///**************** TODO-END ****************/
//
//int main()
//{
//    StudentInfo student;
//    // 输入学生信息
//    student.inputStudentInfo();
//    // 输出学生信息
//    student.printStudentInfo();
//
//    return 0;
//}