class Solution 
{
public:
    bool isPrintable(vector<vector<int>>& targetGrid) 
    {
        int m=targetGrid.size();
        int n=targetGrid[0].size();
        vector<vector<int>>graph(61);
        vector<int>xmax(61,-1);
        vector<int>ymax(61,-1);
        vector<int>xmin(61,m);
        vector<int>ymin(61,n);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int color=targetGrid[i][j];
                xmax[color]=max(xmax[color],i);
                xmin[color]=min(xmin[color],i);
                ymax[color]=max(ymax[color],j);
                ymin[color]=min(ymin[color],j);
            }
        }
        
        vector<int>indegree(61,0);
        
        for(int color=1;color<=60;color++)
        {
            for(int i=xmin[color];i<=xmax[color];i++)
            {
                for(int j=ymin[color];j<=ymax[color];j++)
                {
                    if(targetGrid[i][j]!=color)
                    {
                        graph[color].push_back(targetGrid[i][j]);
                        indegree[targetGrid[i][j]]++;
                    }
                }
            }
        }
        
        int cnt=0;
        
        queue<int>q;
        for(int color=1;color<=60;color++)
        {
            if(indegree[color]==0)
            {
                q.push(color);
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            cnt++;
            q.pop();
            for(auto x:graph[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        
        return cnt==60;
    }
};
