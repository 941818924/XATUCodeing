//2.��Բ�İ뾶r=1.5,Բ����h=3����Բ�ܳ���Բ�����Բ��������Բ�������Բ����������������
#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
public:
    Circle(float r, int h)
    {
        this->r = r;
        this->h = h;
    }

    float getCircleGirth()
    {
        return (2 * M_PI * r);
    }

    float getCircleArea()
    {
        return (M_PI * r * r);
    }

    float getBallSurface()
    {
        return (4 * M_PI * r * r);
    }

    float getBallVolume()
    {
        return ((4 * M_PI * r * r * r) / 3);
    }

    float getCylinderVolume()
    {
        return (getCircleArea() * h);
    }

private:
    float r;
    int h;
};

int main()
{
    Circle c(1.5, 3);
    cout << "Բ���ܳ� = " << c.getCircleGirth() << endl;
    cout << "Բ����� = " << c.getCircleArea() << endl;
    cout << "Բ��ı���� = " << c.getBallSurface() << endl;
    cout << "Բ������ = " << c.getBallVolume() << endl;
    cout << "Բ������� = " << c.getCylinderVolume() << endl;
}