//1.给出一百分制成绩，要求输出成绩等级‘A’，‘B’,‘C’,‘D’,‘E’。
//90分以上为‘A’，80-89为‘B’，70-79为‘C’，60-69为‘D’，60分以下为‘E’。
#include <iostream>

using namespace std;

string grade(int a)
{
    if (a >= 0 && a <= 100)
    {
        if (a >= 90)
        {
            return "A";
        }
        else if (a >= 80)
        {
            return "B";
        }
        else if (a >= 70)
        {
            return "C";
        }
        else if (a >= 60)
        {
            return "D";
        }
        else
            return "E";
    }
    else
        return "不在0-100之间";
}

int main()
{
    cout << grade(-10) << endl;
}