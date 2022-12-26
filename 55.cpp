bool jump(vector<int>&nums,int index,vector<int>&dp)
{
    if(index>=(nums.size()-1))
        return dp[index]=true;
    
    if(dp[index]!=-1)
        return dp[index];
    for(int i=1;i<=nums[index];i++)
    {
        if(jump(nums,index+i,dp))
            return dp[index]=true;
    }
    return dp[index]=false;
}
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return jump(nums,0,dp);
    }
};
