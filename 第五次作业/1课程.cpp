/*1.��һ����4��ѧ����5�ſγ̡�1.���һ�ſγ̵�ƽ���֣�2.�ҳ����������Ͽγ̲������ѧ����
������ǵ�ѧ�ź�ȫ���γ̳ɼ���ƽ���ɼ���3.�ҳ�ƽ���ɼ���90���ϻ�ȫ���γ���85�����ϵ�ѧ�����ֱ��3������
*/
#include <iostream>

using namespace std;

float calAvg(float (*a)[5])
{
    double sum = 0.0;
    for (int i = 0; i < 4; i++)
    {
        sum += a[i][0];
    }
    return sum / 4;
}

void fail(float (*a)[5])
{
    for (int i = 0; i < 4; i++)
    {
        float sum = 0, count = 0;
        for (int j = 0; j < 5; j++)
        {
            if (a[i][j] < 60)
            {
                count++;
            }
        }
        if (count >= 2)
        {
            cout << "�� " << i + 1 << " ��ѧ��������������,���ķ���Ϊ�� ";
            for (int j = 0; j < 5; j++)
            {
                sum += a[i][j];
                cout << a[i][j] << " ";
            }
            cout << endl;
            cout << "����ƽ����Ϊ��" << sum / 5 << endl;
        }
    }
}

void excellent(float (*a)[5])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        int sum = 0, count = 0;
        for (j = 0; j < 5; j++)
        {
            sum += a[i][j];
            if (a[i][j] > 85)
            {
                count++;
            }
        }
        if ((sum / 5) > 90 || count == j)
        {
            cout << "��" << i + 1 << "��ѧ��ƽ���ɼ���90���ϻ�ȫ���γ���85������" << endl;
        }
    }
    return;
}

int main()
{
    float grade[4][5] = {{90.0, 91.4, 96.0, 92.3, 91.6},
                         {30.0, 45.2, 59.7, 75.4, 90.6},
                         {45.6, 70.2, 80.6, 95.8, 59.2},
                         {47.6, 85.2, 31.5, 98.6, 24.5}};
    cout << "��һ�ſ�ƽ����Ϊ�� " << calAvg(grade) << endl;
    cout << endl;
    fail(grade);
    cout << endl;
    excellent(grade);
    return 0;
}