class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> res(candies.size(), true);
        int can;
        for (int i = 0; i < candies.size(); i++)
        {
            can = candies[i] + extraCandies;
            for (int j = 0; j < candies.size(); j++)
            {
                if (can < candies[j])
                {
                    res[i] = false;
                    break;
                }
            }
        }
        return res;
    }
};