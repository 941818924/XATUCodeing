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

void add(Fenshu a, Fenshu b)
{
    Fenshu result;
    result.fenzi = a.fenzi * b.fenmu + b.fenzi * a.fenmu;
    result.fenmu = a.fenmu * b.fenmu;
    cout << "��ӵ���: " << result.fenzi << "/" << result.fenmu << endl;
}

void mul(Fenshu a, Fenshu b)
{
    Fenshu result;
    result.fenzi = a.fenzi * b.fenzi;
    result.fenmu = a.fenmu * b.fenmu;
    cout << "��˵���: " << result.fenzi << "/" << result.fenmu << endl;
}

int main()
{
    Fenshu a = {1, 2};
    Fenshu b = {1, 6};
    cout << "����aΪ�� " << a.fenzi << "/" << a.fenmu << endl;
    cout << "����bΪ�� " << b.fenzi << "/" << b.fenmu << endl;
    add(a, b);
    mul(a, b);
    return 0;
}