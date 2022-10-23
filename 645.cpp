class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,0);
        for(auto x:nums)
        {
            dp[x]++;
        }
        vector<int>res(2);
        
        for(int i=0;i<=n;i++)
        {
            if(dp[i]==2)
                res[0]=i;
            if(dp[i]==0 && i!=0)
                res[1]=i;
        }
        return res;
    }
};
