#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float printSum(int a, int b, int c)
{
    float res = 0.0;
    for (int i = 1; i <= a; i++)
    {
        res += i;
    }
    for (int i = 1; i <= b; i++)
    {
        res += pow(i, 2);
    }
    for (int i = 1; i <= c; i++)
    {
        res += pow(i, -1);
    }
    return res;
}
int main()
{
    cout << fixed << setprecision(2) << printSum(100, 50, 10) << endl;
}