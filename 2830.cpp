int sz;
int dfs(int index,vector<vector<int>>&offers,vector<int>&start,vector<int>&dp)
{
    if(index>=sz) return 0;
    
    if(dp[index]!=-1) return dp[index];
    int c2= dfs(index+1,offers,start,dp);
    
    int c=offers[index][2];
    
    int end=offers[index][1];
    auto ele=lower_bound(start.begin(),start.end(),end+1)-start.begin();
    
    return dp[index]=max(c2,c+dfs(ele,offers,start,dp));
}
class Solution 
{
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) 
    {
        vector<int>start;
        sort(offers.begin(),offers.end());
        sz=offers.size();
        for(int i=0;i<sz;i++)
        {
            start.push_back(offers[i][0]);
        }
        vector<int>dp(sz+5,-1);
        
        return dfs(0,offers,start,dp);
    }
};
