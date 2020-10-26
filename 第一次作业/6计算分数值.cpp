//6. 计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。
#include <iostream>

using namespace std;

void printSum()
{
    float res = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (i % 2)
            res += 1.0 / i;
        else
            res -= 1.0 / i;
    }
    cout << res << endl;
}

int main()
{
    printSum();
}