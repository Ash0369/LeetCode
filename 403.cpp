class Solution 
{
public:
    bool canCross(vector<int>& stones) 
    {
        if(stones[1]!=1)
        {
            return false;
        }
        int n=stones.size();
        map<int,int>mp;
        map<int,set<int>>jp;
        
        for(int i=0;i<n;i++)
        {
            mp[stones[i]]=i;
        }
        jp[1]={1};
        
        int index=1;
        while(index<n)
        {
            for(auto x:jp[index])
            {
                //we jumped x so next time x-1,x,x+1
                int nx=stones[index]+x-1;
                if(mp.find(nx)!=mp.end() && mp[nx]>index)
                {
                    jp[mp[nx]].insert(x-1);
                }
                nx=stones[index]+x;
                if(mp.find(nx)!=mp.end() && mp[nx]>index)
                {
                    jp[mp[nx]].insert(x);
                }
                nx=stones[index]+x+1;
                if(mp.find(nx)!=mp.end() && mp[nx]>index)
                {
                    jp[mp[nx]].insert(x+1);
                }
            }
            index++;
        }
        if(jp[n-1].size()>0)
        {
            return true;
        }
        return false;
    }
};
