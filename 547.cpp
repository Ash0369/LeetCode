//Method-1 : BFS


class Solution 
{
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                queue<int>q;
                q.push(i);
                visited[i]=1;
                int j=0;
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(int i=0;i<n;i++)
                    {
                        int x=isConnected[node][i];
                        if(x==1 && !visited[i])
                        {
                            q.push(i);
                            visited[i]=1;
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};
