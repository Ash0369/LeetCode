class Solution 
{
public:
    int numberOfPoints(vector<vector<int>>& nums) 
    {
        vector<int>dp(101,0);
        for(auto x:nums)
        {
            int start=x[0];
            int end=x[1];
            for(int i=start;i<=end;i++)
            {
                dp[i]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=100;i++)
        {
            if(dp[i]==1)
            {
                ans++;
            }
        }
        return ans;
    }
};
