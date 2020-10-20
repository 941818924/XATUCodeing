/*8.在屏幕上输出以下图案：
      *
     ***
    *****
   *******
  *********
 ***********
*************
 ***********
  *********
   *******
    *****
     ***
      *
*/

#include <iostream>

using namespace std;

void myPrint()
{
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7 - i; j++)
            cout << ' ';
        for (int k = 1; k <= 2 * i - 1; k++)
            cout << '*';
        cout << endl;
    }
    for (int i = 1; i <= 7 - 1; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << ' ';
        for (int k = 1; k <= 2 * (7 - i) - 1; k++)
            cout << '*';
        cout << endl;
    }
}

int main()
{
    myPrint();
}