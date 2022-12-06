class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
        int op=0;
        int prev=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=prev)
            {
                op+=prev-nums[i]+1;
                nums[i]=prev+1;
            }
            prev=nums[i];
        }
        return op;
    }
};
