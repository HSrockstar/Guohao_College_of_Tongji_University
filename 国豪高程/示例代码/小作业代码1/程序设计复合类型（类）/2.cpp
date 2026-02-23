#include <iostream>
#include <iomanip>
using namespace std;

class StudentInfo {
    /****************** TODO ******************/
    string name;
    string number;
    string gender;
    string star;
    string hobby;
    string sentence;
    /**************** TODO-END ****************/

public:
    void inputStudentInfo();
    void printStudentInfo();
};

/****************** TODO ******************/
void StudentInfo::inputStudentInfo()
{
    char hobbies[100];
    cin >> name;
    cin >> number;
    if (cin.fail())
    {
        cout << "ÊäÈë´íÎó";
        exit(0);
    }
    cin >> gender >> star;
    cin.ignore();
    cin.getline(hobbies, 100);
    hobby = hobbies;
    cin >> sentence;
    if (gender == "M") gender = "ÄĞ";
    else if (gender == "F") gender = "Å®";
    else
    {
        cout << "ÊäÈë´íÎó";
        exit(0);
    }
    if (hobby == "\\") hobby = "ÎŞ";
    if (star == "Ari") star = "°×Ñò×ù";
    else if (star == "Tau") star = "½ğÅ£×ù";
    else if (star == "Gem") star = "Ë«×Ó×ù";
    else if (star == "Cnc") star = "¾ŞĞ·×ù";
    else if (star == "Leo") star = "Ê¨×Ó×ù";
    else if (star == "Vir") star = "´¦Å®×ù";
    else if (star == "Lib") star = "Ìì³Ó×ù";
    else if (star == "Sco") star = "ÌìĞ«×ù";
    else if (star == "Sgr") star = "ÉäÊÖ×ù";
    else if (star == "Cap") star = "Ä¦ôÉ×ù";
    else if (star == "Aqu") star = "Ë®Æ¿×ù";
    else if (star == "Pis") star = "Ë«Óã×ù";
    else star = "ÎŞ";
    if (sentence == "\\") sentence = "ÎŞ";
}

void StudentInfo::printStudentInfo()
{
    cout << "ĞÕÃû£º" << name
        << "\nÑ§ºÅ£º" << number
        << "\nĞÔ±ğ£º" << gender
        << "\nĞÇ×ù£º" << star
        << "\n°®ºÃ£º" << hobby
        << "\nÔùÑÔ£º" << sentence;
}
/**************** TODO-END ****************/

int main()
{
    StudentInfo student;
    // ÊäÈëÑ§ÉúĞÅÏ¢
    student.inputStudentInfo();
    // Êä³öÑ§ÉúĞÅÏ¢
    student.printStudentInfo();

    return 0;
}