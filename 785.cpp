//Method-1 : BFS

class Solution 
{
public:
    bool make_color(int node,vector<vector<int>>&graph,vector<int>&color)
    {
        int size=graph[node].size();
        queue<int>q;
        q.push(node);
        color[node]=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            for(auto it:graph[front])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[front];
                    q.push(it);
                }
                else if(color[it]==color[front])
                {
                    return false;
                }
            }
        }
        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!make_color(i,graph,color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//Method-2: DFS

class Solution 
{
public:
    bool make_color(int node,int parent,vector<vector<int>>& graph,vector<int>&color)
    {
        color[node]=1-color[parent];  
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                if(!make_color(it,node,graph,color))
                {
                    return false;
                }
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!make_color(i,0,graph,color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
