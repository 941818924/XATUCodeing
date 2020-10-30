//一个数如果恰好等于不包含它本身所有因子之和，这个数就称为"完数"。
//例如，6的因子为1、2、3，而6=1+2+3，因此6是"完数"。 编程序找出1-1000之内的所有完数。
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