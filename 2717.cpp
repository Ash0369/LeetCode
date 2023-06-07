class Solution 
{
public:
    int semiOrderedPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                if(ans!=0)
                {
                    ans--;
                }
                ans+=(i);
            }
            if(nums[i]==n)
            {
                ans+=n-i-1;
            }
        }
        return ans;
    }
};
