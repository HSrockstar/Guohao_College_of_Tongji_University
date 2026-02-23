#pragma once

#define MAX_STU_NUM			512	//假设每班名单的人数不超过511人（含重复的学生）
#define MAX_NAME_LEN			32	//假设姓名不超过31个字符（15.5个汉字）

/* 每个学生的信息，包括学号和姓名两项 */
struct student {
	int no;
	char name[MAX_NAME_LEN];
};

/* 读指定文件中的学生列表
	1、stu中存放原始顺序，不排序、不去重
	2、stu（实参是数组）最多存放max_num-1个学生，最后用学号0表示结束
	3、返回值是实际读入的学生个数 */
int read_stulist(const char* filename, struct student *stu, const int max_num);

/* 打印读到的学生信息
	1、按原始顺序打印，不排序、不去重
	2、最后再打印学生总数
	3、返回值始终为0 */
int print_stulist(const char *prompt, const struct student* stu, const int stu_num);	

