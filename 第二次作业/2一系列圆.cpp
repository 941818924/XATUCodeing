//2.设圆的半径r=1.5,圆柱高h=3，求圆周长，圆面积，圆球表面积，圆球体积，圆柱体积。输出计算结果
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
    cout << "圆的周长 = " << c.getCircleGirth() << endl;
    cout << "圆的面积 = " << c.getCircleArea() << endl;
    cout << "圆球的表面积 = " << c.getBallSurface() << endl;
    cout << "圆球的体积 = " << c.getBallVolume() << endl;
    cout << "圆柱的体积 = " << c.getCylinderVolume() << endl;
}