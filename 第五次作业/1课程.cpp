/*1.有一个班4个学生，5门课程。1.求第一门课程的平均分；2.找出有两门以上课程不及格的学生，
输出他们的学号和全部课程成绩及平均成绩；3.找出平均成绩在90以上或全部课程在85分以上的学生。分别编3个函数
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
            cout << "第 " << i + 1 << " 个学生挂了两科以上,他的分数为： ";
            for (int j = 0; j < 5; j++)
            {
                sum += a[i][j];
                cout << a[i][j] << " ";
            }
            cout << endl;
            cout << "他的平均分为：" << sum / 5 << endl;
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
            cout << "第" << i + 1 << "个学生平均成绩在90以上或全部课程在85分以上" << endl;
        }
    }
    return;
}

int main()
{
    float grade[4][5] = {{90.0, 91.4, 96.0, 92.3, 91.6},
                         {30.0, 45.2, 60.7, 75.4, 90.6},
                         {45.6, 70.2, 80.6, 95.8, 59.2},
                         {47.6, 85.2, 31.5, 98.6, 24.5}};
    cout << "第一门课平均分为： " << calAvg(grade) << endl;
    cout << endl;
    fail(grade);
    cout << endl;
    excellent(grade);
    return 0;
}