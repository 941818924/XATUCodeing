class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> result;
        int ans = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (*it > nums[i])
                {
                    ans++;
                }
            }
            result.push_back(ans);
            ans = 0;
        }
        return result;
    }
};