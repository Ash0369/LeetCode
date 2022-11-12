class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        vector<pair<int,int>>graph[n+1];
        
        for(auto x:times)
        {
            graph[x[0]].push_back({x[2],x[1]});
            //graph[x[1]].push_back({x[2],x[0]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,k});
        dp[k]=true;
        while(!pq.empty())
        {
           
                auto node=pq.top();
                pq.pop();
                
                for(auto it:graph[node.second])
                {
                    int d=it.first;
                    int ele=it.second;
                    if(dp[ele]>node.first+d)
                    {
                        pq.push({node.first+d,ele});
                        dp[ele]=node.first+d;
                    } 
                }
        }
        for(auto x:dp)
        {
            if(x==INT_MAX)
                return -1;
        }
        sort(dp.begin(),dp.end());
        return dp[n];
    }
};
