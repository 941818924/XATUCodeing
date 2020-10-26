/*10.
求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
例如：2+22+222+2222+22222
*/
#include <iostream>

using namespace std;

int printSum(int a)
{
    int sum = 0, tmp = 0;
    for (int i = 0; i < 5; i++)
    {
        tmp = tmp * 10 + a;
        sum += tmp;
    }
    return sum;
}

int main()
{
    int i;
    cout << "Please enter a number :" << endl;
    cin >> i;
    cout << "sum is : " << printSum(i) << endl;
}