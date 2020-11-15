/*1.��10��ѧ����ÿ��ѧ�������ݰ���ѧ�ţ�������3�ſγ̵ĳɼ����Ӽ���
����10��ѧ�����ݣ�Ҫ�����3�ſγ���ƽ���ɼ����Լ���߷�ѧ��������
������ѧ�ţ�������3�ſγ̳ɼ���ƽ��������
Ҫ��
������ģ���ú���ʵ��*/
#include <iostream>
#include <iomanip>

using namespace std;
#define N 5 //Ϊ�����������д5

struct Student
{
    int num;
    char name[20];
    int score[3];
};

void print(struct Student stu[])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        cout << setw(10) << stu[i].num << "  " << stu[i].name << "\t";
        for (j = 0; j < 3; j++)
            cout << stu[i].score[j] << "  ";
        cout << endl;
    }
}

void input(struct Student stu[])
{
    int i, j;
    for (i = 0; i < N; i++)
    {

        cout << "�����" << i + 1 << "��ѧ����ѧ��" << endl;
        cin >> stu[i].num;
        cout << "�����" << i + 1 << "��ѧ��������" << endl;
        cin >> stu[i].name;
        for (j = 0; j < 3; j++)
        {
            cout << "�����" << i + 1 << "��ѧ���ĵ�" << j + 1 << "���ɼ�" << endl;
            cin >> stu[i].score[j];
        }
    }
}
void average(struct Student stu[])
{

    int i, j;
    float sum;
    for (i = 0; i < N; i++)
    {

        for (j = 0; j < 3; j++)

            sum += stu[i].score[j];
    }
    sum = sum / (3 * N);
    cout << "3�ſε���ƽ���ɼ�:" << sum << endl;
}

void highscores(struct Student stu[])
{

    int i, j, sum;
    float average;
    int max = 0, maxi = 0;
    for (i = 0; i < N; i++)
    {
        sum = 0;
        for (j = 0; j < 3; j++)
            sum += stu[i].score[j];
        if (sum > max)
        {
            max = sum;
            maxi = i;
        }
        average = max / 3.0;
    }
    cout << endl;
    cout << "��߷ֵ�ѧ����ѧ�š�����:  " << stu[maxi].num << "  " << stu[maxi].name << endl;
    cout << stu[maxi].name << " �����ſγɼ�Ϊ: ";
    for (j = 0; j < 3; j++)
    {
        cout << stu[maxi].score[j] << " ";
    }
    cout << endl;
    cout << stu[maxi].name << " ��ƽ����Ϊ�� " << average << endl;
}

int main()
{
    struct Student stu[N] = {{0001, "Zhang San", {10, 20, 30}},
                             {0002, "Li Si", {20, 30, 40}},
                             {0003, "Wang Wu", {35, 45, 55}},
                             {0004, "Du Liu", {55, 65, 75}},
                             {0005, "Ma Qi", {70, 80, 95}}}; //��������
    //struct Student stu[N];
    //input(stu);
    print(stu);
    average(stu);
    highscores(stu);
    return 0;
}