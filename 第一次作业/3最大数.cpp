//3.��10�����������ֵ��
#include <iostream>
#include <ctime>

using namespace std;

void findMax(int a[])
{
    int max = a[0];
    for (int i = 1; i < 10; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    cout << "���ֵΪ��" << max << endl;
}

int main()
{
    int res[10];
    srand((int)time(NULL));
    cout << "�����Ϊ��";
    for (int i = 0; i < 10; i++)
    {
        res[i] = rand() % 100;
        cout << res[i] << ' ';
    }
    cout << endl;
    findMax(res);
}