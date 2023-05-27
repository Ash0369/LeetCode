int dp[50005];
int dfs(int index,vector<int>&stone)
{
    if(index==stone.size())
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int n=stone.size();
    int ans=-1e9;
    int score=0;
    for(int i=0;i<3;i++)
    {
        if(index+i>=n)
        {
            break;
        }
        score+=stone[i+index];
        int got=dfs(index+i+1,stone);
        ans=max(ans,score-got);
    }
    return dp[index]=ans;
}
class Solution 
{
public:
    string stoneGameIII(vector<int>& stoneValue) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=dfs(0,stoneValue);
        if(ans==0)
        {
            return "Tie";
        }
        else if(ans>0)
        {
            return "Alice";
        }
        return "Bob";
    }
};
