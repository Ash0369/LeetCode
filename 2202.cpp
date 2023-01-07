class Solution 
{
public:
    int maximumTop(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(n==1)
        {
            if(k%2==0)
                return nums[0];
            return -1;
        }
        if(k>nums.size())
        {
            sort(nums.begin(),nums.end());
            return nums[n-1];
        }
        int mx=0;
        for(int i=0;i<k-1;i++)
        {
            mx=max(mx,nums[i]);
        }
        if(k<n)
            mx=max(mx,nums[k]);
        return mx;
    }
};
