class Solution 
{
public:
    int arrayPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),greater<int>());
        
        int ans=0;
        
        for(int i=1;i<nums.size();i=i+2)
        {
            ans=ans+nums[i];
        }
        return ans;
    }
};
