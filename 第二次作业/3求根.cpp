//3.求ax2+bx+c=0的根。分别考虑d=b2-4ac大于0、等于0、小于0这三种情况
#include <iostream>
#include <cmath>

using namespace std;

float calculate(int a, int b, int c)
{
    int flag = (b * b) - (4 * a * c);
    if (flag > 0)
    {
        cout << "方程有两根，x1 = " << (-b + sqrt(flag)) / (2 * a) << "  x2 = " << (-b - sqrt(flag)) / (2 * a) << endl;
    }
    else if (flag == 0)
    {
        cout << "方程有一根，x1 = x2 = " << -b / (2 * a);
    }
    else
        cout << "方程无解" << endl;
}
int main()
{
    calculate(1, -2, 1);
}