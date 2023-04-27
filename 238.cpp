class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int ele=1;
        int z=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                z++;
                continue;
            }
            ele=ele*nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0 && z>1)
            {
                nums[i]=0;
            }
            else if(nums[i]==0 && z==1)
            {
                nums[i]=ele;
            }
            else if(nums[i]!=0)
            {
                if(z>0)
                {
                    nums[i]=0;
                    continue;
                }
                nums[i]=ele/nums[i];
            }
            
        }
        return nums;
    }
};
