//Method-1 : Dijkstra Algorthim using Queue


class Solution 
{
public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
        {
        vector<pair<int,int>>vec[n];
        vector<int>dp(n,INT_MAX);
        for(auto x:flights)
        {
            int source=x[0];
            int dest=x[1];
            int price=x[2];
            
            vec[source].push_back({dest,price});
        }
        
        queue<pair<int,int>>q;
        q.push({src,0});
        int stop=0;
        while(!q.empty())
        {
            int sze=q.size();
            for(int i=0;i<sze;i++)
            {
                auto node=q.front();
                int start=node.first;
                int price=node.second;
                q.pop();
                
                for(auto x:vec[start])
                {
                    int dest=x.first;
                    int charge=x.second;
                    
                    if(dp[dest]>(price+charge) && stop<=k)
                    {
                        q.push({dest,price+charge});
                        dp[dest]=price+charge;
                    }
                } 
            }
            stop++;
        }
        
        if(dp[dst]==INT_MAX)
            return -1;
        return dp[dst];
    }
};
