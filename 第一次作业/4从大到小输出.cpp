//4.将三个数按从大到小输出。
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
    cout << "从大到小：";
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << ' ';
    }
}

int main()
{
    int res[3];
    srand((int)time(NULL));
    cout << "随机数为：";
    for (int i = 0; i < 3; i++)
    {
        res[i] = rand() % 100;
        cout << res[i] << ' ';
    }
    cout << endl;
    printFromMaxToMin(res);
}