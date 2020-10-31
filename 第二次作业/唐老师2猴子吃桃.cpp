/*猴子第一天摘了若干个桃子，吃了一半，不过瘾，又多吃了1个。第二天早上将
剩余的桃子又吃掉一半，并且又多吃了1个。此后每天都是吃掉前一天剩下的一半
零一个。到第n天再想吃时，发现只剩下1个桃子，问第一天它摘了多少桃子？为了
加强交互性，由用户输入不同的天数n进行递推，即假设第n天的桃子数为1。*/
#include <iostream>

using namespace std;

int peachSum(int days)
{
    int peach = 1;
    for (int i = 0; i < days - 1; i++)
    {
        peach = (peach + 1) * 2;
    }
    return peach;
}
int main()
{
    int n;
    cout << "请输入几天后还剩一个桃子" << endl;
    cin >> n;
    cout << "第一天摘了 " << peachSum(n) << " 个桃子" << endl;
}
