class Solution 
{
public:
    int minimumSum(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=1e9;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[j]>nums[i] && nums[j]>nums[k])
                    {
                        ans=min(ans,nums[i]+nums[j]+nums[k]);
                    }
                }
            }
        }
        if(ans==1e9)
        {
            return -1;
        }
        return ans;
    }
};
