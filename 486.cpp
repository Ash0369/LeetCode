int dp[21][21][21];
int dfs(vector<int>&nums,int index,int l,int r)
{
    if(index==nums.size())
    {
        return 0;
    }
    if(dp[index][l][r]!=-1)
    {
        return dp[index][l][r];
    }
    int ans1=nums[r]-dfs(nums,index+1,l,r-1);
    int ans2=nums[l]-dfs(nums,index+1,l+1,r);
    return dp[index][l][r]=max(ans1,ans2);
}
class Solution 
{
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        return dfs(nums,0,0,nums.size()-1)>=0;
    }
};
