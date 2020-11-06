class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int plus = 0, times = 1;
        while (n > 0)
        {
            plus += n % 10;
            times *= n % 10;
            n /= 10;
        }
        return times - plus;
    }
};