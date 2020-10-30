#include <iostream>
#include <vector>

using namespace std;

void mySort(vector<int> &a, int n)
{
    for (int i = 0; i < 8; i++)
    {
        if (a[i] > n)
        {
            for (int j = 8; j >= i; j--)
            {
                a[j + 1] = a[j];
            }
            a[i] = n;
            break;
        }
        else
            a[8] = n;
    }
}

int main()
{
    vector<int> a(9);
    int num;
    for (int i = 0; i < 8; i++)
    {
        cout << "请输入a[" << i << "]";
        cin >> a[i];
    }
    cout << "请输入要插入的数" << endl;
    cin >> num;
    mySort(a, num);
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
}