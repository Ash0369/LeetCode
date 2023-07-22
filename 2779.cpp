class Solution 
{
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int ans=1;
        int left=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]-nums[left]>(2*k))
            {
                left++;
            }
            else
            {
                ans=max(ans,i-left+1);
            }
        }
        return ans;
    }
};
