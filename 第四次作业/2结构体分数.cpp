/*2.用结构体定义一个分数的结构，用于表示 2/3, 5/6这样的分数，并用函数实现分数的加法和乘法。
加法输入样例：（1，2），（1，6）-> (4，6)
乘法输入样例：（1，2），（1，6）-> (1，12)*/
#include <iostream>

using namespace std;

struct Fenshu
{
    int fenzi;
    int fenmu;
};

int findNumber(int a, int b) //用最大公约数进行约分
{
    if (a < b)
    {
        int tmp = b;
        b = a;
        a = tmp;
    }
    int c = b;
    while (a % b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return c;
}

void add(Fenshu a, Fenshu b)
{
    int fz = a.fenzi * b.fenmu + b.fenzi * a.fenmu;
    int fm = a.fenmu * b.fenmu;
    pair<int, int> p(fz / findNumber(fz, fm), fm / findNumber(fz, fm));
    if (p.second == 1) //考虑化简
    {
        cout << "相加等于: " << p.first << endl;
    }
    else if (p.second == -1)
    {
        cout << "相加等于: " << 0 - p.first << endl;
    }
    else
    {
        cout << "相加等于: " << p.first << "/" << p.second << endl;
    }
}

void sub(Fenshu a, Fenshu b)
{
    int fz = a.fenzi * b.fenmu - b.fenzi * a.fenmu;
    int fm = a.fenmu * b.fenmu;
    pair<int, int> p(fz / findNumber(fz, fm), fm / findNumber(fz, fm));
    if (p.second == 1)
    {
        cout << "相减等于: " << p.first << endl;
    }
    else if (p.second == -1)
    {
        cout << "相减等于: " << 0 - p.first << endl;
    }
    else
    {
        cout << "相减等于: " << p.first << "/" << p.second << endl;
    }
}

void mul(Fenshu a, Fenshu b)
{
    int fz = a.fenzi * b.fenzi;
    int fm = a.fenmu * b.fenmu;
    pair<int, int> p(fz / findNumber(fz, fm), fm / findNumber(fz, fm));
    if (p.second == 1)
    {
        cout << "相乘等于: " << p.first << endl;
    }
    else if (p.second == -1)
    {
        cout << "相乘等于: " << 0 - p.first << endl;
    }
    else
    {
        cout << "相乘等于: " << p.first << "/" << p.second << endl;
    }
}

void div(Fenshu a, Fenshu b)
{
    int fz = a.fenzi * b.fenmu;
    int fm = a.fenmu * b.fenzi;
    pair<int, int> p(fz / findNumber(fz, fm), fm / findNumber(fz, fm));
    if (p.second == 1)
    {
        cout << "相除等于: " << p.first << endl;
    }
    else if (p.second == -1)
    {
        cout << "相除等于: " << 0 - p.first << endl;
    }
    else
    {
        cout << "相除等于: " << p.first << "/" << p.second << endl;
    }
}

int main()
{
    Fenshu a = {1, 2};
    Fenshu b = {1, 6};
    cout << "分数a为： " << a.fenzi << "/" << a.fenmu << endl;
    cout << "分数b为： " << b.fenzi << "/" << b.fenmu << endl;
    cout << endl;
    add(a, b);
    sub(a, b);
    mul(a, b);
    div(a, b);
    return 0;
}