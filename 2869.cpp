class Solution 
{
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>dp(100,0);
        int ptr=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            dp[nums[i]]=1;
            while(ptr<=k && dp[ptr]==1)
            {
                ptr++;
            }
            if(ptr==k+1)
            {
                return n-i;
            }
        }
        return 0;
    }
};
