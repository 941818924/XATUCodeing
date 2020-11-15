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

void add(Fenshu a, Fenshu b)
{
    Fenshu result;
    result.fenzi = a.fenzi * b.fenmu + b.fenzi * a.fenmu;
    result.fenmu = a.fenmu * b.fenmu;
    cout << "相加等于: " << result.fenzi << "/" << result.fenmu << endl;
}

void mul(Fenshu a, Fenshu b)
{
    Fenshu result;
    result.fenzi = a.fenzi * b.fenzi;
    result.fenmu = a.fenmu * b.fenmu;
    cout << "相乘等于: " << result.fenzi << "/" << result.fenmu << endl;
}

int main()
{
    Fenshu a = {1, 2};
    Fenshu b = {1, 6};
    cout << "分数a为： " << a.fenzi << "/" << a.fenmu << endl;
    cout << "分数b为： " << b.fenzi << "/" << b.fenmu << endl;
    add(a, b);
    mul(a, b);
    return 0;
}