/*2.�ýṹ�嶨��һ�������Ľṹ�����ڱ�ʾ 2/3, 5/6�����ķ��������ú���ʵ�ַ����ļӷ��ͳ˷���
�ӷ�������������1��2������1��6��-> (4��6)
�˷�������������1��2������1��6��-> (1��12)*/
#include <iostream>

using namespace std;

struct Fenshu
{
    int fenzi;
    int fenmu;
};

int findNumber(int a, int b) //�����Լ������Լ��
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
    if (p.second == 1) //���ǻ���
    {
        cout << "��ӵ���: " << p.first << endl;
    }
    else if (p.second == -1)
    {
        cout << "��ӵ���: " << 0 - p.first << endl;
    }
    else
    {
        cout << "��ӵ���: " << p.first << "/" << p.second << endl;
    }
}

void sub(Fenshu a, Fenshu b)
{
    int fz = a.fenzi * b.fenmu - b.fenzi * a.fenmu;
    int fm = a.fenmu * b.fenmu;
    pair<int, int> p(fz / findNumber(fz, fm), fm / findNumber(fz, fm));
    if (p.second == 1)
    {
        cout << "�������: " << p.first << endl;
    }
    else if (p.second == -1)
    {
        cout << "�������: " << 0 - p.first << endl;
    }
    else
    {
        cout << "�������: " << p.first << "/" << p.second << endl;
    }
}

void mul(Fenshu a, Fenshu b)
{
    int fz = a.fenzi * b.fenzi;
    int fm = a.fenmu * b.fenmu;
    pair<int, int> p(fz / findNumber(fz, fm), fm / findNumber(fz, fm));
    if (p.second == 1)
    {
        cout << "��˵���: " << p.first << endl;
    }
    else if (p.second == -1)
    {
        cout << "��˵���: " << 0 - p.first << endl;
    }
    else
    {
        cout << "��˵���: " << p.first << "/" << p.second << endl;
    }
}

void div(Fenshu a, Fenshu b)
{
    int fz = a.fenzi * b.fenmu;
    int fm = a.fenmu * b.fenzi;
    pair<int, int> p(fz / findNumber(fz, fm), fm / findNumber(fz, fm));
    if (p.second == 1)
    {
        cout << "�������: " << p.first << endl;
    }
    else if (p.second == -1)
    {
        cout << "�������: " << 0 - p.first << endl;
    }
    else
    {
        cout << "�������: " << p.first << "/" << p.second << endl;
    }
}

int main()
{
    Fenshu a = {1, 2};
    Fenshu b = {1, 6};
    cout << "����aΪ�� " << a.fenzi << "/" << a.fenmu << endl;
    cout << "����bΪ�� " << b.fenzi << "/" << b.fenmu << endl;
    cout << endl;
    add(a, b);
    sub(a, b);
    mul(a, b);
    div(a, b);
    return 0;
}