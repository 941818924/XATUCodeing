//1.����һ�ٷ��Ƴɼ���Ҫ������ɼ��ȼ���A������B��,��C��,��D��,��E����
//90������Ϊ��A����80-89Ϊ��B����70-79Ϊ��C����60-69Ϊ��D����60������Ϊ��E����
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
        return "����0-100֮��";
}

int main()
{
    cout << grade(-10) << endl;
}