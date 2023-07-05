class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int prev_left=0;
        int curr_left=0;
        int ans=0;
        int n=nums.size();
        bool got=false;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                got=true;
                ans=max(ans,prev_left+curr_left);
                prev_left=curr_left;
                curr_left=0;
            }
            else
            {
                curr_left++;
            }
        }
        ans=max(ans,prev_left+curr_left);
        if(got==false)
        {
            ans--;
        }
        return ans;
    }
};
