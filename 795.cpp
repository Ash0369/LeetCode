class Solution 
{
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        int n=nums.size();
        int prev=0;
        int ans=0;
        int old=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=left && nums[i]<=right)
            {
                prev=i-old+1;
                ans=ans+prev;
            }
            else if(nums[i]>right)
            {
                prev=0;
                old=i+1;
            }
            else
            {
                ans+=prev;
            }
        }
        return ans;
    }
};
