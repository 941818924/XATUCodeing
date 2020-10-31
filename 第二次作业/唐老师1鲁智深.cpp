/*��˵��³����һ������Ҵ��������⸮������£����ٷ��ԣ���ʱ���������99�����У�
ֻ����99����ͷ�����峤�ϲ�Ը����³��������������һ���ض�λ�ã�֮���������˵����
�ҿ�ʼ������Χ��һȦ������5���˿��ԳԵ���ͷ�������£������������ƽ�ķ��������к��ж���
������ͷ��Ψ��³����û�г��ϡ����������ĸ�λ�ã�*/
#include <iostream>
#include <queue>

using namespace std;

int calPos(queue<int> &q)
{
    int pos = 1;
    while (q.size() > 1)
    {
        int x = q.front();
        q.pop();
        if (pos == 5)
        {
            pos = 1;
        }
        else
        {
            q.push(x);
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