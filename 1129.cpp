#define pii pair<int,pair<int,int>>
class Solution 
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,{-1,0}});//distance,color,node
        vector<vector<int>>red(n);
        vector<vector<int>>blue(n);
        for(auto x:redEdges)
        {
            red[x[0]].push_back(x[1]);
        }
        for(auto x:blueEdges)
        {
            blue[x[0]].push_back(x[1]);
        }
        vector<int>dpblue(n,INT_MAX);//Distance of every node from 0 reached last blue
        vector<int>dpred(n,INT_MAX);//Distance of every node from 0 reached last red
        //vector<int>col(n,-1);//Last color ,0 for red , 1 for blue
        dpblue[0]=0;
        dpred[0]=0;
        while(!pq.empty())
        {
            int node=pq.top().second.second;
            int dist=pq.top().first;
            int color=pq.top().second.first;
            pq.pop();
            if(color!=1)
            {
                //So take blue
                for(auto x:blue[node])
                {
                   if(dpblue[x]>(dist+1))
                   {
                       dpblue[x]=dist+1;
                       pq.push({dist+1,{1,x}});
                   }
                }
            }
            if(color!=0)
            {
                //So take red
                for(auto x:red[node])
                {
                   if(dpred[x]>(dist+1))
                   {
                       dpred[x]=dist+1;
                       pq.push({dist+1,{0,x}});
                   }
                }
            }  
        }
        
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            if(dpred[i]==INT_MAX && dpblue[i]==INT_MAX)
            {
                continue;
            }
            ans[i]=min(dpred[i],dpblue[i]);
        }
        return ans;
    }
};
