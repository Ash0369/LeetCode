class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<unsigned long>dp(target+10,0);
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(auto x:nums)
            {
                if(i>=x)
                {
                    dp[i]+=dp[i-x];
                }
            }
        }
        return dp[target];
    }
};