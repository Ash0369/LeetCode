class Solution 
{
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int n=nums.size();
        int dir=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]<0 && dir==1)
            {
                return false;
            }
            if(nums[i]-nums[i-1]>0 && dir==-1)
            {
                return false;
            }
            if(nums[i]>nums[i-1])
            {
                dir=1;
            }
            if(nums[i]<nums[i-1])
            {
                dir=-1;
            }
        }
        return true;
    }
};
