class Solution 
{
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        map<int,int>mp;
        int curr=0;
        int n=groupSizes.size();
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++)
        {
            int x=groupSizes[i];
            if(mp.find(x)==mp.end() || mp[x]==-1)
            {
                mp[x]=curr;
                curr++;
                ans.push_back({i});
                if(ans[curr-1].size()==x)
                {
                    mp[x]=-1;
                }
            }
            else
            {
                ans[mp[x]].push_back(i);
                if(ans[mp[x]].size()==x)
                {
                    mp[x]=-1;
                }
            }
        }
        
        return ans;
    }
};
