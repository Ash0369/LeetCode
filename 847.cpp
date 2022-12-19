//https://www.youtube.com/watch?v=iQBxxTZDajU

class Solution 
{
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        int full=(1<<n)-1;
        
        queue<pair<int,pair<int,int>>>q;
        set<pair<int,int>>dp;
        for(int i=0;i<n;i++)
        {
            q.push({i,{0,1<<i}});
            dp.insert({i,1<<i});
        }
        
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            
            int ele=node.first;
            int cover=node.second.first;
            int mask=node.second.second;
            
            for(auto x:graph[ele])
            {
                int nmask=mask|(1<<x);
                if(nmask==full)
                {
                    return cover+1;
                }
                if(dp.find({x,nmask})!=dp.end())
                    continue;
                q.push({x,{cover+1,nmask}});
                dp.insert({x,nmask});
            }
        }
        return 0;
    }
};
