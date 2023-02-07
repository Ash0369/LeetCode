bool check(vector<int>&dp)
{
    for(int i=0;i<=30;i++)
    {
        if(dp[i]>1)
        {
            return false;
        }
    }
    return true;
}
class Solution 
{
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        vector<int>dp(31,0);
        int left=0;
        int n=nums.size();
        int ans=0;
        for(int right=0;right<n;right++)
        {
            int x=nums[right];
            int bit=0;
            while(x>0)
            {
                if((x&1)==1)
                {
                    dp[bit]++;
                }
                x=x>>1;
                bit++;
            }
            while(check(dp)==false)
            {
                int x=nums[left];
                bit=0;
                while(x>0)
                {
                    if((x&1)==1)
                    {
                        dp[bit]--;
                    }
                    x=x>>1;
                    bit++;
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
