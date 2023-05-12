#define ll long long
ll int dp[100005];
ll int dfs(int index,vector<vector<int>>& questions)
{
    if(index>=questions.size())
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    //not pick 
    ll int ans1=dfs(index+1,questions);
    
    //pick
    ll int ans2=questions[index][0]+dfs(index+questions[index][1]+1,questions);
    
    return dp[index]=max(ans1,ans2);
}
class Solution 
{
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        memset(dp,-1,sizeof(dp));
        return dfs(0,questions);
    }
};
