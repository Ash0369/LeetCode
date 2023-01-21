//Method-1 :

int dfs(int val,int node,vector<vector<int>>&graph,int &del,vector<bool>&dp,vector<int>& nums)
{
    dp[node]=true;
    int v=nums[node];
    int ans=0;
    for(auto x:graph[node])
    {
        if(dp[x]==true)
            continue;
        int cnt=dfs(val,x,graph,del,dp,nums);
        if(cnt==-1)
            return -1;
        if(cnt==val)
        {
            del++;
        }
        else if((cnt+v)==val)
        {
            v=0;
            del++;
        }
        else
        {
            ans+=cnt;
        }
    }
    if(ans==val)
    {
        ans=0;
        del++;
    }
    else if((ans+v)==val)
    {
        v=0;
        ans=0;
        del++;
    }
    if(v==0 && ans!=0) 
        return -1;
    if(v==val)
    {
        del++;
        if(ans!=0)
            return -1;
        return 0;
        
    }
    return ans+v;
}
class Solution 
{
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n=nums.size();
        vector<vector<int>>graph(n);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        int ans=0;
        int s=0;
        for(auto x:nums)
            s=s+x;
        for(int i=1;i<=s;i++)
        {
            if(s%i!=0)
                continue;
            vector<bool>dp(n,false);
            int del=0;
            if(dfs(i,0,graph,del,dp,nums)==0)
            {
                if(ans<del)
                {
                    ans=max(ans,del);
                }
                
            }
        }      
        if(ans==0) 
            return 0;
        return ans-1;
    }
};


//Method-2 : 

int dfs(int val,int node,int parent,vector<vector<int>>&graph,vector<int>& nums)
{
    int v=nums[node];
    for(auto x:graph[node])
    {
        if(x==parent)
            continue;
        v+=dfs(val,x,node,graph,nums);
    }
    if(v==val)
        return 0;
    return v;
}
class Solution 
{
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n=nums.size();
        vector<vector<int>>graph(n);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        int ans=0;
        int s=0;
        for(auto x:nums)
            s=s+x;
        for(int i=1;i<=s;i++)
        {
            if(s%i!=0)
                continue;
            if(dfs(i,0,-1,graph,nums)==0)
            {
                ans=max(ans,s/i);
            }
        }      
        if(ans==0) 
            return 0;
        return ans-1;
    }
};
