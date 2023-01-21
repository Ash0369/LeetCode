vector<int>xorr;
vector<int>num;
vector<vector<bool>>dp;
vector<vector<int>>rec;
int dfs(int node,int parent,vector<vector<int>>&graph,vector<int>&curr)
{
    int ans=num[node];
    for(auto x:curr)
    {
        dp[x][node]=true;
        dp[node][x]=true;
    }
    curr.push_back(node);
    for(auto x:graph[node])
    {
        
        if(x==parent)
            continue;
        rec.push_back({parent,x});
        ans^=dfs(x,node,graph,curr);
    }
    xorr[node]=ans;
    
    curr.pop_back();
    return ans;
}
class Solution 
{
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n=nums.size();
        xorr.clear();
        xorr.resize(n,0);
        num=nums;
        dp.clear();
        dp.resize(n,vector<bool>(n,false));
        rec.clear();
        vector<vector<int>>graph(n);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int>curr;
        int all=dfs(0,-1,graph,curr);
        int ans=INT_MAX;
        
       
        for(int i=0;i<rec.size();i++)
        {
            for(int j=i+1;j<rec.size();j++)
            {
                int a=rec[i][1];
                int b=rec[j][1];
                
               
                if(dp[a][b]==true || dp[b][a]==true)
                {
                    //same subtree
                    int c1=xorr[a]^xorr[b];
                    int c2=xorr[b];
                    int c3=all^xorr[a];
                    int res=max(c1,max(c2,c3))-min(c1,min(c2,c3));
                    
                    ans=min(ans,res);
                }
                else
                {
                    int c1=xorr[a];
                    int c2=xorr[b];
                    int c3=all^xorr[a]^xorr[b];
                    int res=max(c1,max(c2,c3))-min(c1,min(c2,c3));
                    ans=min(ans,res);
                }
            }
        }
        return ans;
    }
};
