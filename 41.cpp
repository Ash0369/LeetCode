class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            while(ele>=1 && ele<=n && nums[ele-1]!=ele)
            {
                swap(nums[ele-1],nums[i]);
                ele=nums[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
};
