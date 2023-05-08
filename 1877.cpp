class Solution 
{
public:
    int minPairSum(vector<int>& nums) 
    {
        int left=1;
        int right=1e6;
        int ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=nums.size()-1;
        while(i<=j)
        {
           ans=max(ans,nums[i]+nums[j]);
           i++;
           j--;
         }
        return ans;
    }
};
