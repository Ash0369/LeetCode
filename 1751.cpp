
int dfs(int index,vector<int>&start,vector<int>&end,vector<int>&v,int k,vector<vector<int>>&dp)
{
    
    if(index>=start.size())
    {
        return 0;
    }
    if(dp[index][k]!=-1)
    {
        return dp[index][k];
    }
    //Not attend event
    int ans1=dfs(index+1,start,end,v,k,dp);
    
    //attend
    int index1=upper_bound(start.begin(),start.end(),end[index])-start.begin();
    int ans2=0;
    
    if(k>0)
    ans2=v[index]+dfs(index1,start,end,v,k-1,dp);
    return dp[index][k]=max(ans1,ans2);
}
class Solution 
{
public:
    int maxValue(vector<vector<int>>& events, int k) 
    {
        sort(events.begin(),events.end());
        vector<int>start;
        vector<int>end;
        vector<int>v;
        for(auto x:events)
        {
            start.push_back(x[0]);
            end.push_back(x[1]);
            v.push_back(x[2]);
        }
        vector<vector<int>>dp(start.size()+2,vector<int>(k+2,-1));
        return dfs(0,start,end,v,k,dp);
    }
};
