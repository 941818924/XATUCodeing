//2. 判断1000年---2000年之间的闰年
#include <iostream>

using namespace std;

void year()
{
    for (int i = 1000; i <= 2000; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
            cout << i << ' ';
    }
}

int main()
{
    year();
}