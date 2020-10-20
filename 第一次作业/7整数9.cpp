//7. 编写程序数一下 1到 100 的所有整数中出现多少个数字9。
#include <iostream>

using namespace std;

void print9()
{
    for (int i = 1; i < 100; i++)
    {
        if (i == 9 || i % 10 == 9 || i / 10 == 9)
            cout << i << ' ';
    }
}

int main()
{
    print9();
}