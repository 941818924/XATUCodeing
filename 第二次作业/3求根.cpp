//3.��ax2+bx+c=0�ĸ����ֱ���d=b2-4ac����0������0��С��0���������
#include <iostream>
#include <cmath>

using namespace std;

float calculate(int a, int b, int c)
{
    int flag = (b * b) - (4 * a * c);
    if (flag > 0)
    {
        cout << "������������x1 = " << (-b + sqrt(flag)) / (2 * a) << "  x2 = " << (-b - sqrt(flag)) / (2 * a) << endl;
    }
    else if (flag == 0)
    {
        cout << "������һ����x1 = x2 = " << -b / (2 * a);
    }
    else
        cout << "�����޽�" << endl;
}
int main()
{
    calculate(1, -2, 1);
}