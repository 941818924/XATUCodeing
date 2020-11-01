/*据说，鲁智深一天中午匆匆来到开封府大相国寺，想蹭顿饭吃，当时大相国寺有99个和尚，
只做了99个馒头，智清长老不愿得罪鲁智深，便把他安排在一个特定位置，之后对所有人说，从
我开始报数（围成一圈），第5个人可以吃到馒头（并退下），按照这个公平的方法，所有和尚都吃
到了馒头，唯独鲁智深没有吃上。请问他在哪个位置？*/
#include <iostream>
#include <queue>

using namespace std;

int calPos(queue<int> &q)
{
    int pos = 1, tmp;
    while (q.size() > 1)
    {
        tmp = q.front();
        q.pop();
        if (pos == 5)
        {
            pos = 1;
        }
        else
        {
            q.push(tmp);
            pos++;
        }
    }
    return q.front();
}

int main()
{
    queue<int> res;
    for (int i = 1; i <= 100; i++)
    {
        res.push(i);
    }
    cout << calPos(res) << endl;
}