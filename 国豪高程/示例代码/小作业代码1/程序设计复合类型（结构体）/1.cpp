#include <iostream>
#include <iomanip>
using namespace std;

struct StudentInfo {
    // 回想一下，static和const的作用是什么？
    static const int MAX_NAME_LEN = 20;
    static const int MAX_MAJOR_LEN = 40;

    char name[MAX_NAME_LEN] = {}; // 学生姓名
    char major[MAX_MAJOR_LEN] = {}; // 专业
    int year = 0; // 入学年份
    double score = 0.0; // 平均绩点
};

void printStudentInfo(const StudentInfo student)
{
    // 实际上，这里传入的参数使用引用更好
    /****************** TODO ******************/
    cout << "姓名：" << student.name << endl;
    cout << "专业：" << student.major << endl;
    cout << "入学年份：" << student.year << endl;
    cout << "平均绩点：" << fixed << setprecision(2) << student.score << endl;
    /**************** TODO-END ****************/
}

int main()
{
    StudentInfo student;
    // 输入学生信息
    cout << "请输入学生信息：" << endl;
    cout << "姓名：";
    // 思考：什么时候可以使用::访问结构体内部的成员？
    cin.getline(student.name, StudentInfo::MAX_NAME_LEN);
    cout << "专业：";
    cin.getline(student.major, StudentInfo::MAX_MAJOR_LEN);
    cout << "入学年份：";
    cin >> student.year;
    cout << "平均绩点：";
    cin >> student.score;

    // 输出学生信息
    cout << "学生信息：" << endl;
    printStudentInfo(student);

    return 0;
}