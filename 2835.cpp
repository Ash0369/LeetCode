class Solution 
{
public:
    int minOperations(vector<int>& nums, int target) 
    {
        vector<int>dp(32,0);
        for(int i=0;i<nums.size();i++)
        {
            int ele=nums[i];
            for(int i=0;i<31;i++)
            {
                if((ele&(1<<i))>0)
                {
                    dp[i]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<31;i++)
        {
            if((target&(1<<i))==0)
            {
                dp[i+1]+=(dp[i]/2);
            }
            else
            {
                
                if(dp[i]>0)
                {
                    dp[i]--;
                    dp[i+1]+=(dp[i]/2);
                }
                else
                {
                    bool res=false;
                    for(int j=i+1;j<31;j++)
                    {
                        if(dp[j]>0)
                        {
                            for(int k=j;k>i;k--)
                            {
                                res=true;
                                ans++;
                                dp[k]--;
                                dp[k-1]++;
                                dp[k-1]++;
                            }
                            break;
                        }
                    }
                    if(res==false)
                    {
                        return -1;
                    }
                    dp[i]--;
                    dp[i+1]+=(dp[i]/2);
                }
            }
            
        }
        return ans;
    }
};
