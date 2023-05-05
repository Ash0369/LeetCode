class Solution 
{
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        int book=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=book)
            {
                ans+=book+1-nums[i];
                nums[i]=book+1;
            }
            book=nums[i];
        }
        return ans;
    }
};
