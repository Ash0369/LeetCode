//Method-1 :  Memoization with 3 pointers


int score(vector<int>&nums,vector<int>&multipliers,int low,int high,int i,vector<vector<int>>&dp)
{
    if(high<low)
        return 0;
    if(i>=multipliers.size())
        return 0;
    if(dp[low][i]==-1)
    {
        int start=(nums[low]*multipliers[i])+score(nums,multipliers,low+1,high,i+1,dp);
        int end=(nums[high]*multipliers[i])+score(nums,multipliers,low,high-1,i+1,dp);
    
        dp[low][i]=max(start,end);
    }
    return dp[low][i];
    
}
class Solution 
{
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        int n=nums.size();
        int m=multipliers.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return score(nums,multipliers,0,n-1,0,dp);
    }
};


//Method-2 : Memoization with 2 pointers

int score(vector<int>&nums,vector<int>&multipliers,int low,int i,vector<vector<int>>&dp)
{
    int n=nums.size();
    if(i>=multipliers.size())
        return 0;
    if(dp[low][i]==-1)
    {
        int start=(nums[low]*multipliers[i])+score(nums,multipliers,low+1,i+1,dp);
        int end=(nums[n-1-i+low]*multipliers[i])+ score(nums,multipliers,low,i+1,dp);
    
        dp[low][i]=max(start,end);
    }
    return dp[low][i];
    
}
class Solution 
{
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        int n=nums.size();
        int m=multipliers.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return score(nums,multipliers,0,0,dp);
    }
};
