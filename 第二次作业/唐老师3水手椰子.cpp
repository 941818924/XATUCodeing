/*五个水手在岛上发现一堆椰子，先由第1个水手把椰子分为等量的5堆，
还剩下1个给了猴子，自己藏起1堆。然后，第2个水手把剩下的4堆混合
后重新分为等量的5堆，还剩下1个给了猴子，自己藏起1堆。以后第3、4个
水手依次按此方法处理。最后，第5个水手把剩下的椰子分为等量的5堆后，
同样剩下1个给了猴子。请用迭代法编程计算并输出原来这堆椰子至少有多少个。*/

//看不懂题的意思，没思路。以下程序是百度的（差不多搞懂了）

#include <iostream>

using namespace std;

int main()
{
    int i = 1, j, sum; //i为单堆数量，j为循环变量，sum为总个数
    while (1)          //从小到大一直循环找出满足条件最小的数
    {
        sum = i * 5 + 1;         //尝试每一个可能的数
        for (j = 4; j >= 0; j--) //五个人，循环五次
        {
            if (sum % 4)
                break;             //如果不能整除，代表无法分为4份，不满足条件，退出进行下一轮循环
            sum = sum * 5 / 4 + 1; //推出上一个人总共有多少椰子
        }
        if (j == 0)
            break; //如果连续循环五次，代表找到了满足条件的这个数，退出整个while
        i++;       //继续尝试下一个i
    }
    cout << sum << endl;
}