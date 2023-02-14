//https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/discuss/1008950/Simple-C%2B%2B-solution

class Solution 
{
public:
    int checkWays(vector<vector<int>>& pairs) 
    {
        unordered_map<int,unordered_set<int>>mp;
        for(auto x:pairs)
        {
            mp[x[0]].insert(x[1]);
            mp[x[1]].insert(x[0]);
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto x:mp)
        {
            pq.push({x.second.size(),x.first});
        }
        
        int n=pq.size();
        bool multiple=false;
        unordered_set<int>visited;
        
        while(!pq.empty())
        {
            int sz=pq.top().first;
            int ele=pq.top().second;
            
            pq.pop();
            int par=0;
            int mx_size=n+1;
            if(visited.size()>0)
            {
                for(auto x:mp[ele])
                {
                    if(mp[x].size()<mx_size && visited.find(x)!=visited.end())
                    {
                        par=x;
                        mx_size=mp[x].size();
                    }
                }
            }
            
            visited.emplace(ele);
            if(par==0)
            {
                if(sz!=(n-1))
                {
                    return 0;
                }
                continue;
            }
            
            for(auto x:mp[ele])
            {
                if(x==par)
                {
                    continue;
                }
                if(mp[par].find(x)==mp[par].end())
                {
                    return 0;
                }
            }
            
            if(mx_size==sz)
            {
                multiple=true;
            }
        }
        
        if(multiple)
        {
            return 2;
        }
        return 1;
    }
};
