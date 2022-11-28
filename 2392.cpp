/*
Form Directed Graphs out of the orderings in rowConditions and colConditions
Check these graphs for Acyclicity. If any of the graphs is cyclic, ordering is not possible. Hence, return [].
Now, we are confirmed that the graphs are DAG. Form topological sorts for the rowConditions and colConditions
Let the topological sort from rowConditions be rowSort and that from colConditions be colSort.
rowSort will determine the position of the element row-wise.
colSort will determine the position of the element col-wise.
*/


void toposort(vector<int>&indegree,int k,vector<int>&res,vector<vector<int>>&graph)
{
    queue<int>q;
    for(int i=1;i<=k;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    
    while(!q.empty())
    {
        int node=q.front();
        res.push_back(node);
        q.pop();
        for(auto x:graph[node])
        {
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
        
    }
}
bool dfs(int node,int intial,vector<vector<int>>&adj,vector<int>&color)
{
    if(color[node]!=-1)
    {
        if(color[node]==intial)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    color[node]=!intial;
    for(auto x:adj[node])
    {
        if(dfs(x,color[node],adj,color)==false)
        {
            return false;
        }
    }
    return true;
}
bool detect_cycle(vector<vector<int>>&graph,int k)
{
    vector<int>dp(k+1,-1);
    for(int i=1;i<=k;i++)
    {
        if(dp[i]!=-1)
        {
            if(dfs(i,0,graph,dp)==false)
                return false;
        }
    }
    return true;
}
class Solution 
{
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        vector<int>indegree_up(k+1,0);//Wil store Indegree of up-down
        vector<int>indegree_lr(k+1,0);//Will store Indegree of left-right
        vector<vector<int>>graph_up(k+1);//Will store graph of up-down
        vector<vector<int>>graph_left(k+1);//Will store graph of left-right
        for(auto x:rowConditions)
        {
            indegree_up[x[1]]++;
            graph_up[x[1]].push_back(x[0]);
            graph_up[x[0]].push_back(x[1]);
        }
        for(auto x:colConditions)
        {
            indegree_lr[x[1]]++;
            graph_left[x[1]].push_back(x[0]);
            graph_left[x[0]].push_back(x[1]);
        }
        
        /*
        This Method for Checking will not able to properly detect cycle as Might be we got a indegree 0 but futher conditions are like that it is crosing each other.
        
        If we want to continue this method then we have to check condition that up,left array which we are forming below there size should be of k , if not k then it is cycle so return {}.
        
        
        bool a=false;
        bool b=false;
        //If Graph has Cycle it cannot be Toposorted so if indegree  are not 0 in any of array then we will return {}
        for(int i=1;i<=k;i++)
        {
            if(indegree_up[i]==0)
                a=true;
            if(indegree_lr[i]==0)
                b=true; 
        }
        
         if(a==false || b==false)
            return {};
        
        */
        //To detect Cycle in the graph
        if(!detect_cycle(graph_up,k) || !detect_cycle(graph_left,k))
            return {};
        
        

         
        vector<int>up;//Store Toposort of up-down
        vector<int>left;//Store Toposort of Left-Right
        
        toposort(indegree_up,k,up,graph_up);
        toposort(indegree_lr,k,left,graph_left);
        
        
        if(up.size()!=k || left.size()!=k)
            return {};
        
        vector<vector<int>>ans(k,vector<int>(k));//Store Final Matrix
        
        map<int,int>mp;
        
        for(int i=0;i<k;i++)
        {
            mp[left[i]]=i;//We are storing Number-->Toposort position in left-right
        }
        for(int i=0;i<k;i++)
        {
            //ans[i] --> 0th row then 1st row line by line we will fill
            //up[i] --> Which element belong to ith row is given by up[i]
            //mp[up[i]] --> Toposort position of that number in left-right
            
            //[i][mp[up[i]]] --> Position in Board
            
            //up[i] --> That Number itself
            ans[i][mp[up[i]]]=up[i];
        }
        return ans;
    }
};
