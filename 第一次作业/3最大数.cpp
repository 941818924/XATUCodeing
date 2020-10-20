//3.求10个整数中最大值。
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
    cout << "最大值为：" << max << endl;
}

int main()
{
    int res[10];
    srand((int)time(NULL));
    cout << "随机数为：";
    for (int i = 0; i < 10; i++)
    {
        res[i] = rand() % 100;
        cout << res[i] << ' ';
    }
    cout << endl;
    findMax(res);
}