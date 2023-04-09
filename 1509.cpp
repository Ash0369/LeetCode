class Solution 
{
public:
    int minDifference(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1 || n==2 || n==3 || n==4)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=nums[n-1]-nums[0];
        
        //3 Large Remove
        ans=min(ans,nums[n-4]-nums[0]);
        
        //3 small Remove
        ans=min(ans,nums[n-1]-nums[3]);
        
        //2 small and 1 Large Remove
        ans=min(ans,nums[n-2]-nums[2]);
        
        //1 small and 2 Large Remove
        ans=min(ans,nums[n-3]-nums[1]);
        
        return ans;
    }
};
