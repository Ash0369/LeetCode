class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        int slow=nums[0];
        int fast=nums[0];
        
        while(true)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)
            {
                break;
            }
        }
        int slow2=nums[0];
        
        while(slow!=slow2)
        {
            slow=nums[slow];
            slow2=nums[slow2];
        }
        return slow;
    }
};
