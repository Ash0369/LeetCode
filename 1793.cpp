class Solution 
{
public:
    int maximumScore(vector<int>& nums, int k) 
    {
        int left=k;
        int right=k;
        
        int ans=nums[k];
        int n=nums.size();
        int mn=nums[k];
        for(int i=0;i<=n+5;i++)
        {
            if(left-1>=0 && right+1<n)
            {
                if(nums[left-1]>=nums[right+1])
                {
                    mn=min(mn,nums[left-1]);
                    left--;
                }
                else
                {
                    mn=min(mn,nums[right+1]);
                    right++;
                }
            }
            else if(left-1>=0)
            { 
                mn=min(mn,nums[left-1]);
                left--; 
            }
            else if(right+1<n)
            {
                mn=min(mn,nums[right+1]);
                right++;
            }
            ans=max(ans,mn*(right-left+1));
        }
        return ans;
    }
};
