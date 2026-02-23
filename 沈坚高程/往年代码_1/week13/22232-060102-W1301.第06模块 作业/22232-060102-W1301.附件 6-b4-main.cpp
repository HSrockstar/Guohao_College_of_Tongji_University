#include <iostream>
#include <cstdio>
#include <conio.h>
using namespace std;

#include "6-b4.h"

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter(const char *prompt = "")
{
	if (prompt==NULL || prompt[0] ==0) //代替strlen(prompt)==0的作用，目的是为了防止后面不小心使用系统函数而特地不加<cstring>头文件
		cout << endl << "按回车键继续";
	else
		cout << endl << prompt << "，按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：细节可能有错，若发现，请及时反映
***************************************************************************/
int main()
{
    if (1) {
        char  s1[]="abcdefghijklmnopqrstuvwxyz";
        char  s2[]="abcdefghijklmnopqrstuvwxyz\0UVWXYZ";
        char  s3[]="";
        char *p4 =NULL;

        cout << "tj_strlen()测试部分：" << endl;
        cout << "1.s1      的长度应该是26，实际是：" << tj_strlen(s1)      << endl;
        cout << "2.s2      的长度应该是26，实际是：" << tj_strlen(s2)      << endl;
        cout << "3.&s2[27] 的长度应该是6， 实际是：" << tj_strlen(&s2[27]) << endl;
        cout << "4.s3      的长度应该是0， 实际是：" << tj_strlen(s3)      << endl;
        cout << "5.p4      的长度认为是0， 实际是：" << tj_strlen(p4)      << endl;

        wait_for_enter("tj_strlen() 测试完成");
        }

    if (1) {
        char  s1[80]="abcdefghij";
        char  s2[]="abcde";
        char  s3[]="hello\0UVWXYZ";
        char  s4[]="";
        char *p5=NULL;

        cout << "tj_strcat()测试部分：" << endl;
        cout << "1.s1的输出应该是abcdefghij，                实际是：" << s1 << endl;
        cout << "  s1的长度应该是10，                        实际是：" << tj_strlen(s1) << endl;

        cout << "2.s1的输出应该是abcdefghijabcde，           实际是：" << tj_strcat(s1, s2) << endl;
        cout << "  s1的长度应该是15，                        实际是：" << tj_strlen(s1)     << endl;

        cout << "3.s1的输出应该是abcdefghijabcdehello，      实际是：" << tj_strcat(s1, s3) << endl;
        cout << "  s1的长度应该是20，                        实际是：" << tj_strlen(s1)     << endl;

        cout << "4.s1的输出应该是abcdefghijabcdehelloUVWXYZ，实际是：" << tj_strcat(s1, &s3[6]) << endl;
        cout << "  s1的长度应该是26，                        实际是：" << tj_strlen(s1)         << endl;

        cout << "5.s1的输出应该是abcdefghijabcdehelloUVWXYZ，实际是：" << tj_strcat(s1, s4) << endl;
        cout << "  s1的长度应该是26，                        实际是：" << tj_strlen(s1)     << endl;

        cout << "6.s1的输出应该是abcdefghijabcdehelloUVWXYZ，实际是：" << tj_strcat(s1, p5) << endl;
        cout << "  s1的长度应该是26，                        实际是：" << tj_strlen(s1)     << endl;

        cout << "7.p5的输出应该是<NULL>，                    实际是：" << (tj_strcat(p5, s1)==NULL ? "<NULL>":tj_strcat(p5, s1)) << endl;
        cout << "  p5的长度应该是0，                         实际是：" << tj_strlen(p5)     << endl;

        cout << "8.p5的输出应该是<NULL>，                    实际是：" << (tj_strcat(p5, NULL)==NULL ? "<NULL>":tj_strcat(p5, NULL)) << endl;
        cout << "  p5的长度应该是0，                         实际是：" << tj_strlen(p5)     << endl;

        wait_for_enter("tj_strcat() 测试完成");
        }

    if (1) {
        char  s1[80] = "abcdefghij";
        char  s2[] = "abcde";
        char  s3[] = "hello\0UVWXYZ";
        char  s4[] = "";
        char* p5 = NULL;

        cout << "tj_strncat()测试部分：" << endl;
        cout << "1.s1的输出应该是abcdefghij，              实际是：" << s1 << endl;
        cout << "  s1的长度应该是10，                      实际是：" << tj_strlen(s1) << endl;

        cout << "2.s1的输出应该是abcdefghijabc，           实际是：" << tj_strncat(s1, s2, 3) << endl;
        cout << "  s1的长度应该是13，                      实际是：" << tj_strlen(s1) << endl;

        cout << "3.s1的输出应该是abcdefghijabchello，      实际是：" << tj_strncat(s1, s3, 100) << endl;
        cout << "  s1的长度应该是18，                      实际是：" << tj_strlen(s1) << endl;

        cout << "4.s1的输出应该是abcdefghijabchelloUVWXYZ，实际是：" << tj_strncat(s1, &s3[6], 6) << endl;
        cout << "  s1的长度应该是24，                      实际是：" << tj_strlen(s1) << endl;

        cout << "5.s1的输出应该是abcdefghijabchelloUVWXYZ，实际是：" << tj_strncat(s1, s4, 2) << endl;
        cout << "  s1的长度应该是24，                      实际是：" << tj_strlen(s1) << endl;

        cout << "6.s1的输出应该是abcdefghijabchelloUVWXYZ，实际是：" << tj_strncat(s1, p5, 100) << endl;
        cout << "  s1的长度应该是24，                      实际是：" << tj_strlen(s1) << endl;

        cout << "7.p5的输出应该是<NULL>，                  实际是：" << (tj_strncat(p5, s1, 100) == NULL ? "<NULL>" : tj_strncat(p5, s1, 100)) << endl;
        cout << "  p5的长度应该是0，                       实际是：" << tj_strlen(p5) << endl;

        cout << "8.p5的输出应该是<NULL>，                  实际是：" << (tj_strncat(p5, NULL, 1) == NULL ? "<NULL>" : tj_strncat(p5, NULL, 1)) << endl;
        cout << "  p5的长度应该是0，                       实际是：" << tj_strlen(p5) << endl;

        wait_for_enter("tj_strncat() 测试完成");
    }

    if (1) {
        char  s0[80];
        char  s1[80]="abcdefghijklm";
        char  s2[]="abcde";
        char  s3[]="hello\0UVWXYZ";
        char  s4[]="";
        char *p5=NULL;
        char *p6=NULL;

        cout << "tj_strcpy()测试部分：" << endl;
        cout << "1.s1的输出应该是abcdefghijklm，   实际是：" << s1            << endl;
        cout << "  s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        cout << "2.s1的输出应该是abcde，           实际是：" << tj_strcpy(s1, s2) << endl;
        cout << "  s1的长度应该是5，               实际是：" << tj_strlen(s1)     << endl;

        cout << "3.s1的输出应该是UVWXYZ，          实际是：" << tj_strcpy(s1, &s3[6]) << endl;
        cout << "  s1的长度应该是6，               实际是：" << tj_strlen(s1)         << endl;

        cout << "4.s1的输出应该是hello，           实际是：" << tj_strcpy(s1, s3) << endl;
        cout << "  s1的长度应该是5，               实际是：" << tj_strlen(s1)     << endl;

        cout << "5.s1的输出应该是--，              实际是：-" << tj_strcpy(s1, s4) << '-' << endl;
        cout << "  s1的长度应该是0，               实际是："  << tj_strlen(s1)     << endl;

        tj_strcpy(s0, s2);
        tj_strcat(s0, s3);
        cout << "6.s0的输出应该是abcdehelloUVWXYZ，实际是：" << tj_strcat(s0, &s3[6]) << endl;
        cout << "  s0的长度应该是16，              实际是：" << tj_strlen(s0)         << endl;

        cout << "7.s0的输出应该是--，              实际是：-" << tj_strcpy(s0, p5) << '-' << endl;
        cout << "  s0的长度应该是0，               实际是："  << tj_strlen(s0)     << endl;

        cout << "8.p5的输出应该是<NULL>，          实际是："  << (tj_strcpy(p5, s0)==NULL ? "<NULL>" : tj_strcpy(p5, s0)) << endl;
        cout << "  p5的长度应该是0，               实际是："  << tj_strlen(p5)     << endl;

        cout << "9.p5的输出应该是<NULL>，          实际是："  << (tj_strcpy(p5, p6)==NULL ? "<NULL>" : tj_strcpy(p5, p6)) << endl;
        cout << "  p5的长度应该是0，               实际是："  << tj_strlen(p5)     << endl;

        wait_for_enter("tj_strcpy() 测试完成");
        }

    if (1) {
        char  s0[80];
        char  s1[80]="abcdefghijklm";
        char  s2[]="abcde";
        char  s3[]="hello\0UVWXYZ";
        char  s4[]="";
        char *p5=NULL;
        char *p6=NULL;

        cout << "tj_strncpy()测试部分：" << endl;
        cout << "1. s1的输出应该是abcdefghijklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        cout << "2. s1的输出应该是hellofghijklm，   实际是：" << tj_strncpy(s1, s3, 10) << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1)          << endl;

        tj_strcpy(s1, "abcdefghijklm");
        cout << "3. s1的输出应该是hellofghijklm，   实际是：" << tj_strncpy(s1, s3, 5) << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1)         << endl;

        tj_strcpy(s1, "abcdefghijklm");
        cout << "4. s1的输出应该是heldefghijklm，   实际是：" << tj_strncpy(s1, s3, 3) << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1)         << endl;

        tj_strcpy(s1, "abcdefghijklm");
        cout << "5. s1的输出应该是abcdefghijklm，   实际是：" << tj_strncpy(s1, s4, 2) << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1)         << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], s3, 10);
        cout << "6. s1的输出应该是abcdhellojklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], s3, 5);
        cout << "7. s1的输出应该是abcdhellojklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], s3, 3);
        cout << "8. s1的输出应该是abcdhelhijklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], &s3[6], 10);
        cout << "9. s1的输出应该是abcdUVWXYZklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

		wait_for_enter("tj_strncpy() 测试暂停");

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], &s3[6], 6);
        cout << "10.s1的输出应该是abcdUVWXYZklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], &s3[6], 3);
        cout << "11.s1的输出应该是abcdUVWhijklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strncpy(s0, s2, tj_strlen(s2));
        s0[tj_strlen(s2)] = 0;
        cout << "12.s0的输出应该是abcde，           实际是：" << s0            << endl;
        cout << "   s0的长度应该是5，               实际是：" << tj_strlen(s0) << endl;

        cout << "13.s0的输出应该是abcdehello，      实际是：" << tj_strcat(s0, s3) << endl;
        cout << "   s0的长度应该是10，              实际是：" << tj_strlen(s0)     << endl;

        int old_len = tj_strlen(s0);
        tj_strncpy(&s0[10], &s3[6], tj_strlen(&s3[6]));
        s0[old_len + tj_strlen(&s3[6]) ] = 0;
        cout << "14.s0的输出应该是abcdehelloUVWXYZ，实际是：" << s0            << endl;
        cout << "   s0的长度应该是16，              实际是：" << tj_strlen(s0) << endl;

        cout << "15.s0的输出应该是abcdehelloUVWXYZ，实际是："  << tj_strncpy(s0, p5, 2) << endl;
        cout << "   s0的长度应该是16，              实际是："  << tj_strlen(s0)     << endl;

        cout << "16.p5的输出应该是<NULL>，          实际是："  << (tj_strncpy(p5, s0, 2)==NULL ? "<NULL>" : tj_strncpy(p5, s0, 2)) << endl;
        cout << "   p5的长度应该是0，               实际是："  << tj_strlen(p5)     << endl;

        cout << "17.p5的输出应该是<NULL>，          实际是："  << (tj_strncpy(p5, p6, 2)==NULL ? "<NULL>" : tj_strncpy(p5, p6, 2)) << endl;
        cout << "   p5的长度应该是0，               实际是："  << tj_strlen(p5)     << endl;

		wait_for_enter("tj_strncpy() 测试完成");
        }

    if (1) {
        char  s1[]="horse";
        char  s2[]="house";
        char  s3[]="hell";
        char  s4[]="hello";
        char  s5[]="hello";
        char  s6[]="hell";
        char  s7[]="hello";
        char  s8[]="hello";
        char  s9[]="hello";
        char  s10[]="hello\0UVWXYZ";
        char  s11[]="HELLO";
        char  s12[]="hello";
        char  s13[]="HeLlO";
        char  s14[]="hElLo";
        char *p15 = NULL;
        char *p16 = NULL;

        cout << "tj_strcmp()测试部分：" << endl;
        cout << "1.s1 和s2 的输出应该是-3，  实际是：" << tj_strcmp(s1,  s2)  << endl;
        cout << "2.s3 和s4 的输出应该是-111，实际是：" << tj_strcmp(s3,  s4)  << endl;
        cout << "3.s5 和s6 的输出应该是111， 实际是：" << tj_strcmp(s5,  s6)  << endl;
        cout << "4.s7 和s8 的输出应该是0，   实际是：" << tj_strcmp(s7,  s8)  << endl;
        cout << "5.s9 和s10的输出应该是0，   实际是：" << tj_strcmp(s9,  s10) << endl;
        cout << "6.s11和s12的输出应该是-32， 实际是：" << tj_strcmp(s11, s12) << endl;
        cout << "7.s13和s14的输出应该是-32， 实际是：" << tj_strcmp(s13, s14) << endl;
        cout << "8.p15和s1 的输出应该是-1，  实际是：" << tj_strcmp(p15, s1)  << endl;
        cout << "  s1 和p15的输出应该是1，   实际是：" << tj_strcmp(s1,  p15) << endl;
        cout << "  p15和p16的输出应该是0，   实际是：" << tj_strcmp(p15, p16) << endl;

		wait_for_enter("tj_strcmp() 测试完成");
        }

    if (1) {
        char  s1[]="horse";
        char  s2[]="house";
        char  s3[]="hell";
        char  s4[]="hello";
        char  s5[]="hello";
        char  s6[]="hell";
        char  s7[]="hello";
        char  s8[]="hello";
        char  s9[]="hello";
        char  s10[]="hello\0UVWXYZ";
        char  s11[]="HELLO";
        char  s12[]="hello";
        char  s13[]="HeLlO";
        char  s14[]="hElLo";
        char s15[] = "HeLlO";
        char s16[] = "hElMo";
        char s17[] = "HeLXO";
        char s18[] = "hEllo";
        char s19[] = "HeL]O";//]=93
        char s20[] = "hEllo";//l=108
        char s21[] = "HeL]O";//]=93
        char s22[] = "hElLo";//L=76
        char s23[] = "HeL O";// =32
        char s24[] = "hEllo";//l=108
        char s25[] = "HeL O";//]=32
        char s26[] = "hElLo";//L=76
        char *p15 = NULL;
        char *p16 = NULL;

        cout << "tj_strcasecmp()测试部分：" << endl;
        cout << "1.s1 和s2 的输出应该是-3，  实际是：" << tj_strcasecmp(s1,  s2)  << endl;
        cout << "2.s3 和s4 的输出应该是-111，实际是：" << tj_strcasecmp(s3,  s4)  << endl;
        cout << "3.s5 和s6 的输出应该是111， 实际是：" << tj_strcasecmp(s5,  s6)  << endl;
        cout << "4.s7 和s8 的输出应该是0，   实际是：" << tj_strcasecmp(s7,  s8)  << endl;
        cout << "5.s9 和s10的输出应该是0，   实际是：" << tj_strcasecmp(s9,  s10) << endl;
        cout << "6.s11和s12的输出应该是0，   实际是：" << tj_strcasecmp(s11, s12) << endl;
        cout << "7.s13和s14的输出应该是0，   实际是：" << tj_strcasecmp(s13, s14) << endl;
        cout << "8.s15和s16的输出应该是-1 ， 实际是：" << tj_strcasecmp(s15, s16) << endl;
        cout << "  s16和s15的输出应该是1 ，  实际是：" << tj_strcasecmp(s16, s15) << endl;
        cout << "9.s17和s18的输出应该是12，  实际是：" << tj_strcasecmp(s17, s18) << endl;
        cout << "  s18和s17的输出应该是-12， 实际是：" << tj_strcasecmp(s18, s17) << endl;
        cout << "10.s19和s20的输出应该是-15，实际是：" << tj_strcasecmp(s19, s20) << endl;
        cout << "   s20和s19的输出应该是15， 实际是：" << tj_strcasecmp(s20, s19) << endl;
        cout << "11.s21和s22的输出应该是-15，实际是：" << tj_strcasecmp(s21, s22) << endl;
        cout << "   s22和s21的输出应该是15， 实际是：" << tj_strcasecmp(s22, s21) << endl;
        cout << "12.s23和s24的输出应该是-76，实际是：" << tj_strcasecmp(s23, s24) << endl;
        cout << "   s24和s23的输出应该是76， 实际是：" << tj_strcasecmp(s24, s23) << endl;
        cout << "13.s25和s26的输出应该是-76，实际是：" << tj_strcasecmp(s25, s26) << endl;
        cout << "   s26和s25的输出应该是76， 实际是：" << tj_strcasecmp(s26, s25) << endl;
        cout << "14.p15和s1 的输出应该是-1， 实际是：" << tj_strcasecmp(p15, s1)  << endl;
        cout << "   s1 和p15的输出应该是1，  实际是：" << tj_strcasecmp(s1,  p15) << endl;
        cout << "   p15和p16的输出应该是0，  实际是：" << tj_strcasecmp(p15, p16) << endl;

		wait_for_enter("tj_strcasecmp() 测试完成");
        }

    if (1) {
        char  s1[]="horse";
        char  s2[]="house";
        char  s3[]="hell";
        char  s4[]="hello";
        char  s5[]="hello";
        char  s6[]="hell";
        char  s7[]="hello";
        char  s8[]="hello";
        char  s9[]="hello";
        char  s10[]="hello\0UVWXYZ";
        char  s11[]="HELLO";
        char  s12[]="hello";
        char  s13[]="HeLlO";
        char  s14[]="hElLo";
        char *p15 = NULL;
        char *p16 = NULL;

        cout << "tj_strncmp()测试部分：" << endl;
        cout << "1.s1 和s2 比较前10个字符的输出应该是-3，  实际是：" << tj_strncmp(s1,  s2,  10) << endl;
        cout << "  s1 和s2 比较前5 个字符的输出应该是-3，  实际是：" << tj_strncmp(s1,  s2,  5)  << endl;
        cout << "  s1 和s2 比较前3 个字符的输出应该是-3，  实际是：" << tj_strncmp(s1,  s2,  3)  << endl;
        cout << "  s1 和s2 比较前2 个字符的输出应该是0，   实际是：" << tj_strncmp(s1,  s2,  2)  << endl;
        cout << "2.s3 和s4 比较前10个字符的输出应该是-111，实际是：" << tj_strncmp(s3,  s4,  10) << endl;
        cout << "  s3 和s4 比较前5 个字符的输出应该是-111，实际是：" << tj_strncmp(s3,  s4,  5)  << endl;
        cout << "  s3 和s4 比较前4 个字符的输出应该是0，   实际是：" << tj_strncmp(s3,  s4,  4)  << endl;
        cout << "3.s5 和s6 比较前10个字符的输出应该是111 ，实际是：" << tj_strncmp(s5,  s6,  10) << endl;
        cout << "  s5 和s6 比较前5 个字符的输出应该是111， 实际是：" << tj_strncmp(s5,  s6,  5)  << endl;
        cout << "  s5 和s6 比较前4 个字符的输出应该是0，   实际是：" << tj_strncmp(s5,  s6,  4)  << endl;
        cout << "4.s7 和s8 比较前10个字符的输出应该是0 ，  实际是：" << tj_strncmp(s7,  s8,  10) << endl;
        cout << "  s7 和s8 比较前5 个字符的输出应该是0，   实际是：" << tj_strncmp(s7,  s8,  5)  << endl;
        cout << "  s7 和s8 比较前4 个字符的输出应该是0，   实际是：" << tj_strncmp(s7,  s8,  4)  << endl;
        cout << "5.s9 和s10比较前10个字符的输出应该是0 ，  实际是：" << tj_strncmp(s9,  s10, 10) << endl;
        cout << "  s9 和s10比较前5 个字符的输出应该是0，   实际是：" << tj_strncmp(s9,  s10, 5)  << endl;
        cout << "  s9 和s10比较前4 个字符的输出应该是0，   实际是：" << tj_strncmp(s9,  s10, 4)  << endl;
		wait_for_enter("tj_strncmp() 测试暂停");

        cout << "6.s11和s12比较前10个字符的输出应该是-32， 实际是：" << tj_strncmp(s11, s12, 10) << endl;
        cout << "  s11和s12比较前5 个字符的输出应该是-32， 实际是：" << tj_strncmp(s11, s12, 5)  << endl;
        cout << "  s11和s12比较前2 个字符的输出应该是-32， 实际是：" << tj_strncmp(s11, s12, 2)  << endl;
        cout << "7.s13和s14比较前10个字符的输出应该是-32， 实际是：" << tj_strncmp(s13, s14, 10) << endl;
        cout << "  s13和s14比较前5 个字符的输出应该是-32， 实际是：" << tj_strncmp(s13, s14, 5)  << endl;
        cout << "  s13和s14比较前2 个字符的输出应该是-32， 实际是：" << tj_strncmp(s13, s14, 2)  << endl;
        cout << "8.p15和s1 比较前2 个字符的输出应该是-1，  实际是：" << tj_strncmp(p15, s1,  2) << endl;
        cout << "  s1 和p15比较前2 个字符的输出应该是1，   实际是：" << tj_strncmp(s1,  p15, 5)  << endl;
        cout << "  p15和p16比较前2 个字符的输出应该是0，   实际是：" << tj_strncmp(p15, p16, 2)  << endl;

		wait_for_enter("tj_strncmp() 测试结束");
        }

    if (1) {
        char  s1[]="horse";
        char  s2[]="house";
        char  s3[]="hell";
        char  s4[]="hello";
        char  s5[]="hello";
        char  s6[]="hell";
        char  s7[]="hello";
        char  s8[]="hello";
        char  s9[]="hello";
        char  s10[]="hello\0UVWXYZ";
        char  s11[]="HELLO";
        char  s12[]="hello";
        char  s13[]="HeLlO";
        char  s14[]="hElLo";
        char s15[] = "HeLlO";
        char s16[] = "hElMo";
        char s17[] = "HeLXO";
        char s18[] = "hEllo";
        char s19[] = "HeL]O";//]=93
        char s20[] = "hEllo";//l=108
        char s21[] = "HeL]O";//]=93
        char s22[] = "hElLo";//L=76
        char s23[] = "HeL O";// =32
        char s24[] = "hEllo";//l=108
        char s25[] = "HeL O";//]=32
        char s26[] = "hElLo";//L=76
        char *p27 = NULL;
        char *p28 = NULL;

        cout << "tj_strcasencmp()测试部分：" << endl;
        cout << "1.s1 和s2 比较前10个字符的输出应该是-3，  实际是：" << tj_strcasencmp(s1,  s2,  10) << endl;
        cout << "  s1 和s2 比较前5 个字符的输出应该是-3，  实际是：" << tj_strcasencmp(s1,  s2,  5)  << endl;
        cout << "  s1 和s2 比较前3 个字符的输出应该是-3，  实际是：" << tj_strcasencmp(s1,  s2,  3)  << endl;
        cout << "  s1 和s2 比较前2 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s1,  s2,  2)  << endl;
        cout << "2.s3 和s4 比较前10个字符的输出应该是-111，实际是：" << tj_strcasencmp(s3,  s4,  10) << endl;
        cout << "  s3 和s4 比较前5 个字符的输出应该是-111，实际是：" << tj_strcasencmp(s3,  s4,  5)  << endl;
        cout << "  s3 和s4 比较前4 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s3,  s4,  4)  << endl;
        cout << "3.s5 和s6 比较前10个字符的输出应该是111 ，实际是：" << tj_strcasencmp(s5,  s6,  10) << endl;
        cout << "  s5 和s6 比较前5 个字符的输出应该是111， 实际是：" << tj_strcasencmp(s5,  s6,  5)  << endl;
        cout << "  s5 和s6 比较前4 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s5,  s6,  4)  << endl;
        cout << "4.s7 和s8 比较前10个字符的输出应该是0 ，  实际是：" << tj_strcasencmp(s7,  s8,  10) << endl;
        cout << "  s7 和s8 比较前5 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s7,  s8,  5)  << endl;
        cout << "  s7 和s8 比较前4 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s7,  s8,  4)  << endl;
        cout << "5.s9 和s10比较前10个字符的输出应该是0 ，  实际是：" << tj_strcasencmp(s9,  s10, 10) << endl;
        cout << "  s9 和s10比较前5 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s9,  s10, 5)  << endl;
        cout << "  s9 和s10比较前4 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s9,  s10, 4)  << endl;
		wait_for_enter("tj_strcasencmp() 测试暂停");

        cout << "6.s11和s12比较前10个字符的输出应该是0，   实际是：" << tj_strcasencmp(s11, s12, 10) << endl;
        cout << "  s11和s12比较前5 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s11, s12, 5)  << endl;
        cout << "  s11和s12比较前2 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s11, s12, 2)  << endl;
        cout << "7.s13和s14比较前10个字符的输出应该是0，   实际是：" << tj_strcasencmp(s13, s14, 10) << endl;
        cout << "  s13和s14比较前5 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s13, s14, 5)  << endl;
        cout << "  s13和s14比较前2 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s13, s14, 2)  << endl;
        cout << "8.s15和s16比较前2个字符的输出应该是0，    实际是：" << tj_strcasencmp(s15, s16, 2) << endl;
        cout << "  s16和s15比较前2个字符的输出应该是0，    实际是：" << tj_strcasencmp(s16, s15, 2) << endl;
        cout << "9.s17和s18比较前4个字符的输出应该是12，   实际是：" << tj_strcasencmp(s17, s18, 4) << endl;
        cout << "  s18和s17比较前4个字符的输出应该是-12，  实际是：" << tj_strcasencmp(s18, s17, 4) << endl;
        cout << "10.s19和s20比较前4个字符的输出应该是-15， 实际是：" << tj_strcasencmp(s19, s20, 4) << endl;
        cout << "   s20和s19比较前4个字符的输出应该是15，  实际是：" << tj_strcasencmp(s20, s19, 4) << endl;
        cout << "11.s21和s22比较前4个字符的输出应该是-15， 实际是：" << tj_strcasencmp(s21, s22, 4) << endl;
        cout << "   s22和s21比较前4个字符的输出应该是15，  实际是：" << tj_strcasencmp(s22, s21, 4) << endl;
        cout << "12.s23和s24比较前4个字符的输出应该是-76， 实际是：" << tj_strcasencmp(s23, s24, 4) << endl;
        cout << "   s24和s23比较前4个字符的输出应该是76，  实际是：" << tj_strcasencmp(s24, s23, 4) << endl;
        cout << "13.s25和s26比较前4个字符的输出应该是-76， 实际是：" << tj_strcasencmp(s25, s26, 4) << endl;
        cout << "   s26和s25比较前4个字符的输出应该是76，  实际是：" << tj_strcasencmp(s26, s25, 4) << endl;
        cout << "14.p27和s1 比较前2 个字符的输出应该是-1， 实际是：" << tj_strcasencmp(p27, s1,  2) << endl;
        cout << "   s1 和p27比较前2 个字符的输出应该是1，  实际是：" << tj_strcasencmp(s1,  p27, 2)  << endl;
        cout << "   p27和p28比较前2 个字符的输出应该是0，  实际是：" << tj_strcasencmp(p27, p28, 2)  << endl;

		wait_for_enter("tj_strcasencmp() 测试完成");
        }

     if (1) {
        char  s1[]="123horseHELLO*#@";
        char  s2[]="1A2b3C*d#E@f";
        char *p3 = NULL;

        cout << "tj_strupr()测试部分：" << endl;
        cout << "1.s1 的输出应该是123HORSEHELLO*#@，实际是：" << tj_strupr(s1) << endl;
        cout << "2.s2 的输出应该是1A2B3C*D#E@F，    实际是：" << tj_strupr(s2) << endl;
        cout << "3.p3 的输出应该是<NULL>，          实际是：" << (tj_strupr(p3)==NULL ? "<NULL>":tj_strupr(p3)) << endl;

		wait_for_enter("tj_strupr() 测试完成");
        }

     if (1) {
        char  s1[]="123horseHELLO*#@";
        char  s2[]="1A2b3C*d#E@f";
        char *p3 = NULL;

        cout << "tj_strlwr()测试部分：" << endl;
        cout << "1.s1 的输出应该是123horsehello*#@，实际是：" << tj_strlwr(s1) << endl;
        cout << "2.s2 的输出应该是1a2b3c*d#e@f，    实际是：" << tj_strlwr(s2) << endl;
        cout << "3.p3 的输出应该是<NULL>，          实际是：" << (tj_strlwr(p3)==NULL ? "<NULL>":tj_strlwr(p3)) << endl;

		wait_for_enter("tj_strlwr() 测试完成");
        }

     if (1) {
        char  s1[]="This is a pencil.";
        char *p2 = NULL;

        cout << "tj_strchr()测试部分：" << endl;
        cout << "1.s1 的输出应该是1，实际是：" << tj_strchr(s1, 'T') << endl;
        cout << "2.s1 的输出应该是3，实际是：" << tj_strchr(s1, 'i') << endl;
        cout << "3.s1 的输出应该是5，实际是：" << tj_strchr(s1, ' ') << endl;
        cout << "4.s1 的输出应该是0，实际是：" << tj_strchr(s1, 'x') << endl;
        cout << "5.p2 的输出应该是0，实际是：" << tj_strchr(p2, 'a') << endl;

		wait_for_enter("tj_strchr() 测试完成");
        }

     if (1) {
        char  s1[]="This is a pencil.";
        char  s2[]="aabbbceddbbbceeeff";
        char  s3[]="abcde";
        char *p4 = NULL;

        cout << "tj_strstr()测试部分：" << endl;
        cout << "1.s1 的输出应该是1， 实际是：" << tj_strstr(s1, "T")      << endl;
        cout << "  s1 的输出应该是3， 实际是：" << tj_strstr(s1, "is")     << endl;
        cout << "  s1 的输出应该是11，实际是：" << tj_strstr(s1, "pencil") << endl;
        cout << "  s1 的输出应该是0， 实际是：" << tj_strstr(s1, "Pencil") << endl;
        cout << "2.s2 的输出应该是3， 实际是：" << tj_strstr(s2, "bb")     << endl;
        cout << "  s2 的输出应该是3， 实际是：" << tj_strstr(s2, "bbb")    << endl;
        cout << "  s2 的输出应该是4， 实际是：" << tj_strstr(s2, "bbc")    << endl;
        cout << "  s2 的输出应该是0， 实际是：" << tj_strstr(s2, "bbbb")   << endl;
        cout << "  s2 的输出应该是6， 实际是：" << tj_strstr(s2, "ce")     << endl;
        cout << "  s2 的输出应该是13，实际是：" << tj_strstr(s2, "cee")    << endl;
        cout << "3.s2 的输出应该是5， 实际是：" << tj_strstr(&s2[5], "bb") << endl;
        cout << "  s2 的输出应该是5， 实际是：" << tj_strstr(s2+5, "bbb") << endl;
        cout << "  s2 的输出应该是6， 实际是：" << tj_strstr(&s2[5], "bbc") << endl;
        cout << "  s2 的输出应该是0， 实际是：" << tj_strstr(s2+5, "bbbb") << endl;
        cout << "  s2 的输出应该是1， 实际是：" << tj_strstr(&s2[5], "ce") << endl;
        cout << "  s2 的输出应该是8， 实际是：" << tj_strstr(s2+5, "cee") << endl;
        cout << "4.s3 的输出应该是1， 实际是：" << tj_strstr(s3, "abcde")  << endl;
        cout << "  s3 的输出应该是0， 实际是：" << tj_strstr(s3, "abcdef") << endl;
        cout << "  s3 的输出应该是0， 实际是：" << tj_strstr(s3, NULL)     << endl;
        cout << "5.p4 的输出应该是0， 实际是：" << tj_strstr(p4, "abc")    << endl;
        cout << "  p4 的输出应该是0， 实际是：" << tj_strstr(p4, NULL)     << endl;

		wait_for_enter("tj_strstr() 测试完成");
        }

     if (1) {
        char  s1[]="This is a pencil.";
        char *p2  = NULL;

        cout << "tj_strrchr()测试部分：" << endl;
        cout << "1.s1 的输出应该是1， 实际是：" << tj_strrchr(s1, 'T') << endl;
        cout << "2.s1 的输出应该是15，实际是：" << tj_strrchr(s1, 'i') << endl;
        cout << "3.s1 的输出应该是10，实际是：" << tj_strrchr(s1, ' ') << endl;
        cout << "4.s1 的输出应该是0， 实际是：" << tj_strrchr(s1, 'x') << endl;
        cout << "5.p2 的输出应该是0， 实际是：" << tj_strrchr(p2, 'a') << endl;

		wait_for_enter("tj_strrchr() 测试完成");
        }

     if (1) {
        char  s1[]="This is a pencil.";
        char  s2[]="aabbbceddbbbceeeff";
        char  s3[]="abcde";
        char *p4 = NULL;

        cout << "tj_strrstr()测试部分：" << endl;
        cout << "1.s1 的输出应该是1， 实际是：" << tj_strrstr(s1, "T")      << endl;
        cout << "  s1 的输出应该是6， 实际是：" << tj_strrstr(s1, "is")     << endl;
        cout << "  s1 的输出应该是11，实际是：" << tj_strrstr(s1, "pencil") << endl;
        cout << "  s1 的输出应该是0， 实际是：" << tj_strrstr(s1, "Pencil") << endl;
        cout << "2.s2 的输出应该是11，实际是：" << tj_strrstr(s2, "bb")     << endl;
        cout << "  s2 的输出应该是10，实际是：" << tj_strrstr(s2, "bbb")    << endl;
        cout << "  s2 的输出应该是11，实际是：" << tj_strrstr(s2, "bbc")    << endl;
        cout << "  s2 的输出应该是0， 实际是：" << tj_strrstr(s2, "bbbb")   << endl;
        cout << "  s2 的输出应该是13，实际是：" << tj_strrstr(s2, "ce")     << endl;
        cout << "  s2 的输出应该是13，实际是：" << tj_strrstr(s2, "cee")    << endl;
        cout << "2.s2 的输出应该是6， 实际是：" << tj_strrstr(&s2[5], "bb") << endl;
        cout << "  s2 的输出应该是5， 实际是：" << tj_strrstr(s2+5, "bbb")  << endl;
        cout << "  s2 的输出应该是6， 实际是：" << tj_strrstr(&s2[5], "bbc") << endl;
        cout << "  s2 的输出应该是0， 实际是：" << tj_strrstr(s2+5, "bbbb") << endl;
        cout << "  s2 的输出应该是8， 实际是：" << tj_strrstr(&s2[5], "ce") << endl;
        cout << "  s2 的输出应该是8， 实际是：" << tj_strrstr(s2+5, "cee")  << endl;
        cout << "4.s3 的输出应该是1， 实际是：" << tj_strrstr(s3, "abcde")  << endl;
        cout << "  s3 的输出应该是0， 实际是：" << tj_strrstr(s3, "abcdef") << endl;
        cout << "  s3 的输出应该是0， 实际是：" << tj_strrstr(s3, NULL)     << endl;
        cout << "5.p4 的输出应该是0， 实际是：" << tj_strrstr(p4, "abc")    << endl;
        cout << "  p4 的输出应该是0， 实际是：" << tj_strrstr(p4, NULL)     << endl;

		wait_for_enter("tj_strrstr() 测试完成");
        }

     if (1) {
        char  s1[]="This is a pencil.";
        char  s2[]="aabbbceddbbbceeeff";
        char  s3[]="";
        char *p4 = NULL;

        cout << "tj_strrev()测试部分：" << endl;
        cout << "1.s1 的输出应该是This is a pencil.，  实际是：" << s1 << endl;
        cout << "  s1 的输出应该是.licnep a si sihT，  实际是：" << tj_strrev(s1) << endl;

        cout << "2.s2 的输出应该是aabbbceddbbbceeeff， 实际是：" << s2 << endl;
        cout << "  s2 的输出应该是ffeeecbbbddecbbbaa， 实际是：" << tj_strrev(s2) << endl;

        cout << "3.s3 的输出应该是--，                 实际是：-" << s3            << "-" << endl;
        cout << "  s3 的输出应该是--，                 实际是：-" << tj_strrev(s3) << "-" << endl;

        cout << "4.p4 的输出应该是<NULL>，             实际是：" << (p4==NULL ? "<NULL>" : p4) << endl;
        cout << "  p4 的输出应该是<NULL>，             实际是：" << (tj_strrev(p4)==NULL ? "<NULL>" : tj_strrev(s3)) << endl;

		wait_for_enter("tj_strrev() 测试完成");
        }

    return 0;
}
