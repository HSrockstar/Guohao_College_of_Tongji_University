//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//struct StudentInfo {
//	static const int MAX_NAME_LEN = 20;
//	static const int MAX_MAJOR_LEN = 30;
//
//	char name[MAX_NAME_LEN] = {};    // 学生姓名
//	char major[MAX_MAJOR_LEN] = {};  // 专业
//	int year = 0;                    // 入学年份
//	double score = 0.0;              // 平均绩点
//
//	StudentInfo(const StudentInfo& info);
//	StudentInfo();
//	void print_info();  // 实际上，这里也可使用运算符重载（进阶课内容）
//};
//
///****************** TODO ******************/
//StudentInfo::StudentInfo(const StudentInfo& info)
//{
//	strcpy_s(name, info.name);
//	strcpy_s(major, info.major);
//	year = info.year;
//	score = info.score;
//}
//StudentInfo::StudentInfo()
//{
//	cin.getline(name, StudentInfo::MAX_NAME_LEN);
//	cin.getline(major, StudentInfo::MAX_MAJOR_LEN);
//	cin >> year;
//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
//	cin >> score;
//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
//}
//void StudentInfo::print_info()
//{
//	cout << name << " " << major << " " <<fixed<< setprecision(2) << year << " " << score << endl;
//}
///**************** TODO-END ****************/
//
//int main()
//{
//	StudentInfo stu1;
//	StudentInfo stu2(stu1);
//
//	// 修改stu1的信息
//	cin.getline(stu1.name, StudentInfo::MAX_NAME_LEN);
//	cin.getline(stu1.major, StudentInfo::MAX_MAJOR_LEN);
//	cin >> stu1.year;
//	cin >> stu1.score;
//
//	// 输出stu1和stu2的信息
//	stu1.print_info();
//	stu2.print_info();
//
//	return 0;
//}