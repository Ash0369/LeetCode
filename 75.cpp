class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int ptr=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==2)
            {
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
    }
};
