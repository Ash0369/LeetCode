//Method-1 : 


class Solution 
{
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        vector<set<int>>graph(n);
        for(auto x:roads)
        {
            graph[x[0]].insert(x[1]);
            graph[x[1]].insert(x[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                int a=graph[i].size();
                int b=graph[j].size();
                if(graph[i].find(j)!=graph[i].end())
                {
                    ans=max(ans,a+b-1);
                }
                else
                {
                    ans=max(ans,a+b);
                }
            }
        }
        return ans;
    }
};


//Method-2 : 

class Solution 
{
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        vector<set<int>>graph(n);
        for(auto x:roads)
        {
            graph[x[0]].insert(x[1]);
            graph[x[1]].insert(x[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int a=graph[i].size();
                int b=graph[j].size();
                if(graph[i].find(j)!=graph[i].end())
                {
                    ans=max(ans,a+b-1);
                }
                else
                {
                    ans=max(ans,a+b);
                }
            }
        }
        return ans;
    }
};
