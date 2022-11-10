class Solution 
{
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=points.size();
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=0;
        int ans=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            int wt=node.first;
            int p=node.second;
            
            int x=points[p][0];
            int y=points[p][1];
            if(dp[p]==1)
            {
                continue;
            }
            
            dp[p]=1;
            ans+=wt;
            for(int i=0;i<n;i++)
            {
                int nx=points[i][0];
                int ny=points[i][1];
                
                int cost=abs(x-nx)+abs(y-ny);
                
                if(dp[i]==0 && i!=p)
                    pq.push({cost,i});
            }
            
        }
        return ans;
    }
};
