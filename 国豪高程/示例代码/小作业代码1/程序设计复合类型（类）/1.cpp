#include <iostream>
#include <iomanip>
using namespace std;

class StudentInfo {
    /****************** TODO ******************/
    char name[100];
    string major;
    int year;
    double gpa;
    /**************** TODO-END ****************/

public:
    void inputStudentInfo();
    void printStudentInfo();
};

/****************** TODO ******************/
void StudentInfo::inputStudentInfo()
{
    cin.getline(name, 100);
    cin >> major >> year >> gpa;
}
void StudentInfo::printStudentInfo()
{
    cout << "学生信息："
        << "\n姓名：" << name
        << "\n专业：" << major
        << "\n入学年份：" << year
        << "\n平均绩点：" << fixed << setprecision(2) << gpa << endl;
}
/**************** TODO-END ****************/

int main()
{
    StudentInfo student;
    // 输入学生信息
    student.inputStudentInfo();
    // 输出学生信息
    student.printStudentInfo();

    return 0;
}