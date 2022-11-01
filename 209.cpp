class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int left=0;
        int right=0;
        int curr=0;
        int ans=INT_MAX;
        for(int right=0;right<n;right++)
        {
            curr+=nums[right];
            while(curr>=target)
            {
                ans=min(ans,right-left+1);
                curr-=nums[left];
                left++;
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};
