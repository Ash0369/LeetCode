class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n=numCourses;
        vector<int>adj[n];
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int>indegree(n,0);
	    queue<int>q;
	    for(int i=0;i<n;i++)
	    {
	        for(auto x:adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
        vector<int>ans;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto x:adj[node])
	        {
	            indegree[x]--;
	            if(indegree[x]==0)
	            {
	                q.push(x);
	            }
	        }
	    }
	    if(ans.size()==n)
	    {
	        return ans;
	    }
	    return {};
    }
};
