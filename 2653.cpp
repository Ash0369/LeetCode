class Solution 
{
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) 
    {
        vector<int>dp(53,0);
        int n=nums.size();
        int left=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                dp[51]++;
            }
            else
            {
                dp[abs(nums[i])]++;
            }
            
            if(i+1<k)
            {
                continue;
            }
            int cnt=0;
            for(int j=50;j>=1;j--)
            {
                if(dp[j]>0)
                {
                    cnt=cnt+dp[j];
                    if(cnt>=x)
                    {
                        ans.push_back(-1*j);
                        break;
                    }
                }
            }
            if(cnt<x)
            {
                ans.push_back(0);
            }
            if(nums[left]>0)
            {
                dp[51]--;
            }
            else
            {
                dp[abs(nums[left])]--;
            }
            left++;
        }
        return ans;
    }
};
