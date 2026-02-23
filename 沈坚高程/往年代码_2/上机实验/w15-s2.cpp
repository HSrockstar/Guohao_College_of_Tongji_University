/*2253744 林觉凯 软工*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（全局只读变量或宏定义不受此限制）
   3、不允许添加其它函数
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;		//某课程的成绩（百分制）
	float weight;	//某课程的学分（权重）
	int   gpa;		//某课程的绩点（同济规则，[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5）
};

struct student {
	int   no;               //学号（虽然用int不够合理，此处不考虑）
	char  name[9];          //假设姓名最长4个汉字
	struct course score[3]; //数组放三门课的成绩（未使用宏定义，函数实现时，直接写3即可）
	float avg_gpa;                      //可增加其它你认为需要增加的结构体成员（限一个），不要则删除本行
};

class gpa_calc {
private:
	struct student stu[N];
	//不再允许增加任何数据成员 
public:
	void input();
	void output_base();
	void output_max();
	int GPA(float value);                    //可增加其它你认为需要增加的成员函数（限一个），不要则删除本行
};

/* 下面给出gpa_calc类的成员函数的体外实现，包括自己增加的
   要求输出必须是cin/cout */
int gpa_calc::GPA(float value)
{
	if (value >= 90)
		return 5;
	if (value >= 80)
		return 4;
	if (value >= 70)
		return 3;
	if (value >= 60)
		return 2;
	return 0;
}
void gpa_calc::input()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		stu[i].avg_gpa = 0;
		cout << "请输入第" << setw(2) << i + 1 << "个学生的信息：";
		cin >> stu[i].no >> stu[i].name;
		for (j = 0; j < 3; j++)
		{
			cin >> stu[i].score[j].value >> stu[i].score[j].weight;
			stu[i].score[j].gpa = GPA(stu[i].score[j].value);
			stu[i].avg_gpa += stu[i].score[j].gpa * stu[i].score[j].weight;
		}
		stu[i].avg_gpa /= (stu[i].score[0].weight + stu[i].score[1].weight + stu[i].score[2].weight);
	}
}
void gpa_calc::output_base()
{
	struct student* ps;
	cout << endl << "10个学生的成绩" << endl;
	cout << "序号 学号    姓名     绩点1 权重1 绩点2 权重2 绩点3 权重3 平均绩点" << endl;
	cout << "==================================================================" << endl;
	cout << setiosflags(ios::left);
	for (ps = stu; ps < stu + N; ps++)
	{
		cout << setw(4) << ps - stu + 1 << " " << setw(7) << ps->no << " " << setw(8) << ps->name;
		for (int i = 0; i < 3; i++)
			cout << " " << setw(5) << ps->score[i].gpa << " " << setw(5) << ps->score[i].weight;
		cout << " " << setw(5) << fixed << setprecision(3) << ps->avg_gpa << endl << resetiosflags(ios::fixed);
	}
	cout << resetiosflags(ios::left);
}
void gpa_calc::output_max()
{
	cout<<endl<<"绩点最高的学生为"<<endl;
	cout << "序号 学号    姓名     绩点1 权重1 绩点2 权重2 绩点3 权重3 平均绩点" << endl;
	cout << "==================================================================" << endl;
	float max = 0;
	for (int i = 0; i < N; i++)
	{
		if (stu[i].avg_gpa > max)
			max = stu[i].avg_gpa;
	}
	cout << setiosflags(ios::left);
	for (int i = 0; i < N; i++)
	{
		if (stu[i].avg_gpa == max)
		{
			struct student* ps = &stu[i];
			cout << setw(4) << ps - stu + 1 << " " << setw(7) << ps->no << " " << setw(8) << ps->name;
			for (int i = 0; i < 3; i++)
				cout << " " << setw(5) << ps->score[i].gpa << " " << setw(5) << ps->score[i].weight;
			cout << " " << setw(5) << fixed << setprecision(3) << ps->avg_gpa << endl << resetiosflags(ios::fixed);
		}
	}
	cout << resetiosflags(ios::left);
}
   /***************************************************************************
	 函数名称：
	 功    能：
	 输入参数：
	 返 回 值：
	 说    明：main函数不准动
   ***************************************************************************/
int main()
{
	gpa_calc g;

	g.input();		//输入10个学生的信息
	g.output_base();	//输出10个学生的基本信息
	g.output_max();	//输出最高（可能有多个）

	return 0;
}

/*
测试数据，复制到cmd即可

2152482 鄂俊伍 76.5 4 82 5 52 2.5
2250411 林俊吉 63 4.5 49 1 87 6
2250821 郭平伟 56 3 76 4 69 5
2251561 任昱扬 44.5 2 83.5 4 87 6
2252584 欧宇轩 91 4 43.5 1 66 3
2252753 阮飞翔 79 6 85.5 3 62 2
2253554 廖海峰 86 3 63 3 77.5 4
2253711 钟沛橙 49.5 3 86 6 93.5 3
2253968 贾文超 81.5 2 64.5 3 87 4
2254174 任奕 73 3 62 2.5 85 5

*/