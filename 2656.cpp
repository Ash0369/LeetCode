class Solution 
{
public:
    int maximizeSum(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int ele=nums[nums.size()-1];
        int ans=(2*ele)+k-1;
        ans=ans*k;
        return ans/2;
    }
};
