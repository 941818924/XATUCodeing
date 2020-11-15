/*1.有10个学生，每个学生的数据包括学号，姓名，3门课程的成绩，从键盘
输入10个学生数据，要求输出3门课程总平均成绩，以及最高分学生的数据
（包括学号，姓名，3门课程成绩，平均分数）
要求：
各功能模块用函数实现*/
#include <iostream>
#include <iomanip>

using namespace std;
#define N 5 //为方便测试这里写5

struct Student
{
    int num;
    char name[20];
    int score[3];
};

void print(Student stu[])
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

void input(Student stu[])
{
    int i, j;
    for (i = 0; i < N; i++)
    {

        cout << "输入第" << i + 1 << "个学生的学号" << endl;
        cin >> stu[i].num;
        cout << "输入第" << i + 1 << "个学生的姓名" << endl;
        cin >> stu[i].name;
        for (j = 0; j < 3; j++)
        {
            cout << "输入第" << i + 1 << "个学生的第" << j + 1 << "个成绩" << endl;
            cin >> stu[i].score[j];
        }
    }
}
void average(Student stu[])
{

    int i, j;
    float sum;
    for (i = 0; i < N; i++)
    {

        for (j = 0; j < 3; j++)

            sum += stu[i].score[j];
    }
    sum = sum / (3 * N);
    cout << "3门课的总平均成绩:" << sum << endl;
}

void highscores(Student stu[])
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
    cout << "最高分的学生的学号、姓名:  " << stu[maxi].num << "  " << stu[maxi].name << endl;
    cout << stu[maxi].name << " 的三门课成绩为: ";
    for (j = 0; j < 3; j++)
    {
        cout << stu[maxi].score[j] << " ";
    }
    cout << endl;
    cout << stu[maxi].name << " 的平均分为： " << average << endl;
}

int main()
{
    Student stu[N] = {{0001, "Zhang San", {10, 20, 30}},
                      {0002, "Li Si", {20, 30, 40}},
                      {0003, "Wang Wu", {35, 45, 55}},
                      {0004, "Du Liu", {55, 65, 75}},
                      {0005, "Ma Qi", {70, 80, 95}}}; //测试数据
    //Student stu[N];
    //input(stu);
    print(stu);
    average(stu);
    highscores(stu);
    return 0;
}