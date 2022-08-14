//Method-1 : Memoization

bool res(vector<int>&nums,int index,int k,vector<vector<int>>&dp)
{
    if(k==0)
    {
        return true;
    }
    if(index==0)
    {
        if(k==nums[0])
        {
            return true;
        }
        return false;
    }
    if(dp[index][k]==-1)
    {
         bool not_taking=res(nums,index-1,k,dp);
         bool taking=false;
         if(k>nums[index])
         {
            taking= res(nums,index-1,k-nums[index],dp);
         }
         dp[index][k]= not_taking|taking;
    }
    return dp[index][k];
}
class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        for(auto x:nums)
        {
            sum=sum+x;
        }
        if(sum%2!=0)
        {
            return false;
        }
        int k=sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(k+1,-1));
        return res(nums,nums.size()-1,k,dp);
    }
};
