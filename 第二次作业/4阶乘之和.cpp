//4.��Sn=1!+2!+3!+4!+5!+��+n!ֵ֮������n��һ������(n������20)��
#include <iostream>

using namespace std;

long printSum(int a)
{
    long res = 0;
    for (int i = 1; i <= a; i++)
    {
        int tmp = 1;
        for (int j = 1; j <= i; j++)
        {
            tmp *= j;
        }
        res += tmp;
        tmp = 1;
    }
    return res;
}

int main()
{
    int i;
    cout << "������n��ֵ" << endl;
    cin >> i;
    cout << printSum(i) << endl;
}