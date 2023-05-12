//Method-1 : 

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

//Method-2 : 

#define ll long long

class Solution 
{
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n=questions.size();
        ll int dp[100005];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--)
        {
            //not pick
            dp[i]=dp[i+1];
            
            //pick
            
            ll int ans=questions[i][0];
            if(i+questions[i][1]+1<n)
            {
                ans+=dp[i+questions[i][1]+1];
            }
            
            dp[i]=max(dp[i],ans);
            
        }
        return dp[0];
    }
};
