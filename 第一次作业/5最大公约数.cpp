//5.�������������Լ����
#include <iostream>

using namespace std;

int findNumber(int a, int b)
{
    if (a < b)
    {
        int tmp = b;
        b = a;
        a = tmp;
    }
    int c = b;
    while (a % b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int m = 6, n = 8, res;
    cout << "���Լ��Ϊ��" << findNumber(m, n) << endl;
}