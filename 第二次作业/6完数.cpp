//һ�������ǡ�õ��ڲ�������������������֮�ͣ�������ͳ�Ϊ"����"��
//���磬6������Ϊ1��2��3����6=1+2+3�����6��"����"�� ������ҳ�1-1000֮�ڵ�����������
#include <iostream>

using namespace std;

void printSum()
{
    for (int i = 2; i < 1000; i = i + 2)
    {
        int sum = 1;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
                sum = sum + j;
        }
        if (sum == i)
            cout << i << " ";
    }
}
int main()
{
    printSum();
}