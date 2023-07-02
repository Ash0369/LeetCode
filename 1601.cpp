int dfs(int index,int n,vector<vector<int>>&request,vector<int>&change)
{
    if(index==request.size())
    {
        for(int i=0;i<=n;i++)
        {
            if(change[i]!=0)
                return -1e7;
        }
        return 0;
    }
    int f=request[index][0];
    int t=request[index][1];
    
    //approve request or reject
    
    int ans1=dfs(index+1,n,request,change);
    change[f]--;
    change[t]++;
    int ans2=1+dfs(index+1,n,request,change);
    change[f]++;
    change[t]--;
    
    return max(ans1,ans2);
}
class Solution 
{
public:
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        vector<int>change(n+2,0);
        return dfs(0,n,requests,change);
    }
};
