int dfs(int index,int prev,string &s,set<string>& dictionary,vector<vector<int>>&dp)
{
    if(index==s.size())
    {
        return index-prev;
    }
    if(dp[index][prev]!=-1)
    {
        return dp[index][prev];
    }
    int ans1=dfs(index+1,prev,s,dictionary,dp);
    string temp=s.substr(prev,index-prev+1);
    int ans2=0;
    if(dictionary.find(temp)!=dictionary.end())
    {
        ans2=dfs(index+1,index+1,s,dictionary,dp);
    }
    else
    {
        ans2=index-prev+1+dfs(index+1,index+1,s,dictionary,dp);
    }
    return dp[index][prev]=min(ans1,ans2);
}
class Solution 
{
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        int n=s.size();
        set<string>dict(dictionary.begin(),dictionary.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return dfs(0,0,s,dict,dp);
    }
};
