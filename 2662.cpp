class Solution 
{
public:
    int minimumCost(vector<int>& start,vector<int>& target, vector<vector<int>>& specialRoads) 
    {
        map<pair<int,int>,int>mp;
        int ans=abs(start[0]-target[0])+abs(start[1]-target[1]);
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{start[0],start[1]}});
        
        while(!q.empty())
        {
            int x=q.front().second.first;
            int y=q.front().second.second;
            int cost=q.front().first;
            
            q.pop();
            
            ans=min(ans,abs(x-target[0])+abs(y-target[1])+cost);
            
            if(x==target[0] && y==target[1])
            {
                ans=min(ans,cost);
                continue;
            }
            
            for(auto z:specialRoads)
            {
                int destx=z[2];
                int desty=z[3];
                int c=z[4];
                
                int av=1e8;
                if(mp.find({destx,desty})!=mp.end())
                {
                    av=mp[{destx,desty}];
                }
                
                if(cost+abs(x-z[0])+abs(y-z[1])+c<av)
                {
                    mp[{destx,desty}]=cost+abs(x-z[0])+abs(y-z[1])+c;
                    q.push({mp[{destx,desty}],{destx,desty}});
                }  
            }
        }
        return ans;
    }
};
