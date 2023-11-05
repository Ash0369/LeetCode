class Solution 
{
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>graph(n+5);
        vector<int>degree(n,0);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            degree[x[1]]++;
        }
        int ele=0;
        int c;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==0)
            {
                c=i;
                ele++;
            }
        }
        if(ele==1)
            return c;
        return -1;
    }
};
