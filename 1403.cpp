class Solution 
{
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        int sum=0;
        vector<int>ans;
        for(auto x:nums)
            sum+=x;
        sort(nums.begin(),nums.end(),greater<int>());
        int curr=0;
        int i=0;
        while(curr<=sum)
        {
            ans.push_back(nums[i]);
            curr+=nums[i];
            sum-=nums[i];
            i++;
        }
        return ans;
    }
};
