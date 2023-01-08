//Method-1 : 


int mx(vector<int>&nums,int index,int mod,vector<vector<int>>&dp)
{
    if(index==nums.size())
    {
        if(mod==0)
            return 0;
        return -1;
    }
    if(dp[index][mod]!=-1)
        return dp[index][mod];
    int pick=mx(nums,index+1,(mod+(nums[index])%3)%3,dp);
    int not_pick=mx(nums,index+1,mod,dp);
    
    if(pick!=-1)
        pick+=nums[index];
    
    return dp[index][mod]=max(pick,not_pick);
}
class Solution 
{
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return max(0,mx(nums,0,0,dp));
    }
};


//Method-2 : 

