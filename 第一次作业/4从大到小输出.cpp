//4.�����������Ӵ�С�����
#include <iostream>
#include <ctime>

using namespace std;

void printFromMaxToMin(int a[])
{
    int tmp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (a[i] < a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    cout << "�Ӵ�С��";
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << ' ';
    }
}

int main()
{
    int res[3];
    srand((int)time(NULL));
    cout << "�����Ϊ��";
    for (int i = 0; i < 3; i++)
    {
        res[i] = rand() % 100;
        cout << res[i] << ' ';
    }
    cout << endl;
    printFromMaxToMin(res);
}