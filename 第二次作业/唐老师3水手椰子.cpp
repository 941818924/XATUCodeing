/*五个水手在岛上发现一堆椰子，先由第1个水手把椰子分为等量的5堆，
还剩下1个给了猴子，自己藏起1堆。然后，第2个水手把剩下的4堆混合
后重新分为等量的5堆，还剩下1个给了猴子，自己藏起1堆。以后第3、4个
水手依次按此方法处理。最后，第5个水手把剩下的椰子分为等量的5堆后，
同样剩下1个给了猴子。请用迭代法编程计算并输出原来这堆椰子至少有多少个。*/

//看不懂题的意思，没思路。以下程序是百度的（程序也看不懂）

// #include <iostream>

// using namespace std;

// int main()
// {
//     int i = 1, j, n;
//     while (1)
//     {
//         n = i * 5 + 1;
//         for (j = 4; j >= 1; j--)
//         {
//             if (n % 4)
//                 break;
//             n = n * 5 / 4 + 1;
//         }
//         if (j == 0)
//             break;
//         i++;
//     }
//     cout << n << endl;
// }