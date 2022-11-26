class Solution 
{
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        vector<int>indegree(n+1,0);
        vector<vector<int>>graph(n+1);
        for(auto x:relations)
        {
            indegree[x[1]]++;
            graph[x[0]].push_back(x[1]);
        }
        
        queue<int>q;
        vector<int>timer(n+1,0);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                timer[i]=time[i-1];
                ans=max(ans,timer[i]);
            }
        }
       
        while(!q.empty())
        {
            for(auto x:graph[q.front()])
            {
                indegree[x]--;
                timer[x]=max(timer[x],timer[q.front()]);
                if(indegree[x]==0)
                {
                    q.push(x);
                    timer[x]+=time[x-1];
                }
                ans=max(ans,timer[x]);
            }
            q.pop();
        }
        return ans;
    }
};
