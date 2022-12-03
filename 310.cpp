//Method-1 : Give TLE for large Test cases


int dfs(int node, vector<vector<int>>&graph,vector<bool>&dp)
{
    int ans=0;
    for(auto x:graph[node])
    {
        if(dp[x]==true)
            continue;
        dp[x]=true;
        ans=max(ans,dfs(x,graph,dp));
    }
    return 1+ans;
}
class Solution 
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<int>indegree(n);
        vector<vector<int>>graph(n);
        for(auto x:edges)
        {
            indegree[x[0]]++;
            indegree[x[1]]++;
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        vector<int>ans;
        int val=INT_MAX;
        for(int node=0;node<n;node++)
        {
            vector<bool>dp(n+1,false);
            dp[node]=true;
            int depth=0;
            depth=dfs(node,graph,dp);
            if(depth==val)
            {
                ans.push_back(node);
                val=depth;
            }
            else if(depth<val)
            {
                ans.clear();
                ans.push_back(node);
                val=depth;
            }
        }
        return ans;
        
    }
};


//Method-2 : https://leetcode.com/problems/minimum-height-trees/discuss/1630778/C%2B%2B-Simple-Solution-or-Topological-Sort-or-W-Explanation


class Solution 
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<int>indegree(n);
        vector<vector<int>>graph(n);
        for(auto x:edges)
        {
            indegree[x[0]]++;
            indegree[x[1]]++;
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
                indegree[i]=0;
            }
        }
        
        while(!q.empty())
        {
            int sz=q.size();
            ans.clear();
            for(int i=0;i<sz;i++)
            {
                int a=q.front();
                ans.push_back(a);
                q.pop();
                for(auto x:graph[a])
                {
                    indegree[x]--;
                    if(indegree[x]==1)
                    {
                        q.push(x);
                    }
                }
            }
        }
        
        if(n==1)
            ans.push_back(0);
        return ans;
        
    }
};
