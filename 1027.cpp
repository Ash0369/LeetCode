int n;
class Solution 
{
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        n=nums.size();
        vector<vector<int>>dp(1005,vector<int>(1100,1));
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff=nums[j]-nums[i]+505;
                dp[i][diff]=max(dp[i][diff],dp[j][diff]+1);
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};
