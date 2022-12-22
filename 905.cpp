class Solution 
{
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int ptr=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
            {
                int ptr=i;
                while(ptr<n && nums[ptr]%2!=0)
                    ptr++;
                if(ptr==n)
                    break;
                swap(nums[i],nums[ptr]);
            }
        }
        return nums;
    }
};
