//1. 打印100~200之间的素数
#include <iostream>
#include <cmath>

using namespace std;

void printNumber()
{
    int i, j;
    for (i = 101; i <= 200; i += 2)
    {
        for (j = 2; j < sqrt(i); j++)
        {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i))
            cout << i << ' ';
    }
}

int main()
{
    printNumber();
}