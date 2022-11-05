class Solution 
{
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        if(n==1)
            return 1;
        #define ll long long 
        ll int mod=1e9+7;
        
        vector<pair<ll int,ll int>>vec[n];
        vector<ll int>dp(n,1e18);
        vector<ll int>way(n,0); //It stores the number of way by which we can arraive at a node in shortest way
        way[0]=1;
        for(auto x:roads)
        {
            vec[x[0]].push_back({x[1],x[2]});
            vec[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<ll int,ll int>,vector<pair<ll int,ll int>>,greater<pair<ll int,ll int>>>pq;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();  
            ll int covered=node.first;
            ll int source=node.second;
            if(source==n-1)
                break;
            for(auto x:vec[source])
            {
                if(dp[x.first]>covered+x.second)
                {
                    dp[x.first]=covered+x.second;
                    pq.push({covered+x.second,x.first});
                    way[x.first]=(way[source]);//Erased all previous shortest stored in x.first
                   
                }
                else if(dp[x.first]==covered+x.second)
                {
                    way[x.first]=(way[x.first]+way[source])%mod;  //ADD prev and more way we got
                }
            }
        }
        if(dp[n-1]==1e18)
            return -1;
        return way[n-1];
    }
};
