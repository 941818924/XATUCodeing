/*9.求出0～999之间的所有“水仙花数”并输出。
“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3?，则153是一个“水仙花数”。
*/

#include <iostream>

using namespace std;

void printNum()
{
    int a, b, c;
    for (int i = 100; i < 1000; i++)
    {
        a = i / 100;
        b = (i / 10) % 10;
        c = i % 10;
        if (a * a * a + b * b * b * b + c * c * c == i)
            cout << i << ' ';
    }
}

int main()
{
    printNum();
}
