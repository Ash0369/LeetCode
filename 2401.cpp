//Method-1 : 


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


//Method-2 : 


class Solution 
{
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        //If And of all pairs should be zero then at a bit position only 1 number have set 
        //All oher unset
        //So keep taking OR to sum it.
        //And if new element what we are getting is also set at same position
        //Then unset the bits of number from left
        vector<int>dp(31,0);
        int left=0;
        int n=nums.size();
        int ans=0;
        int sum=0;
        for(int right=0;right<n;right++)
        {
            int x=nums[right];
            while((sum&x)!=0)
            {
                sum=sum^nums[left];
                left++;
            }
            sum=sum|x;
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
