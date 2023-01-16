//Method-1 : Dynamic Programming

int dfs(int node,vector<vector<pair<int,int>>>&graph,int available,vector<int>&passingFees, vector<vector<int>>&dp)
{
    int ans=INT_MAX;
    int n=passingFees.size();
    if(node==n-1)
    {
        return passingFees[node];
    }
    
    if(dp[node][available]!=-1)
        return dp[node][available];
    
    for(auto x:graph[node])
    {
        if(available>=x.second)
        {
            int cost=dfs(x.first,graph,available-x.second,passingFees,dp);
            if(cost!=INT_MAX)
            {
                ans=min(ans,cost+passingFees[node]);
            }
        }
    }
    if(ans==INT_MAX)
        return dp[node][available]=INT_MAX;
    
    return dp[node][available]=ans;
}
class Solution 
{
public:
    int minCost(int maxTime,vector<vector<int>>&edges,vector<int>&passingFees) 
    {
        int n=passingFees.size();
        vector<vector<pair<int,int>>>graph(n);
        for(auto x:edges)
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        vector<vector<int>>dp(n,vector<int>(1001,-1));
        int ans=dfs(0,graph,maxTime,passingFees,dp);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};


//Method-2 : Dijkastra


#define pii pair<int,pair<int,int>>
class Solution 
{
public:
    int minCost(int maxTime,vector<vector<int>>&edges,vector<int>&passingFees) 
    {
        int n=passingFees.size();
        vector<vector<pair<int,int>>>graph(n);
        for(auto x:edges)
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({passingFees[0],{0,0}});//Total cost,node,time
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        while(!pq.empty())
        {
            int curr_cost = pq.top().first;
            int curr_node = pq.top().second.first;
            int curr_time = pq.top().second.second;
            pq.pop();
            
            if(curr_node==n-1)
            {
                return curr_cost;
            }
            
            for(auto x:graph[curr_node])
            {
                int new_cost=curr_cost+passingFees[x.first];
                int new_time=curr_time+x.second;
                
                if(new_time<=maxTime && dp[x.first]>new_time)
                {
                    dp[x.first]=new_time;
                    pq.push({new_cost,{x.first,new_time}});
                }
            }
        }
        return -1;
    }
};
