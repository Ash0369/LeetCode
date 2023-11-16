class Solution 
{
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        map<int,int>mp;
        map<int,vector<int>>tree;
        for(auto x:adjacentPairs)
        {
            mp[x[0]]++;
            mp[x[1]]++;
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        int n=adjacentPairs.size();
        n++;
        vector<int>ans(n,1000000);
        for(auto x:mp)
        {
            if(x.second==1)
            {
                if(ans[0]==1000000)
                {
                    ans[0]=x.first;
                }
                else{
                    ans[n-1]=x.first;
                }
            }
        }
        for(int i=0;i<n-2;i++)
        {
            int parent=1000000;
            if(i>0)
            {
                parent=ans[i-1];
            }
            for(auto x:tree[ans[i]])
            {
                if(x!=parent)
                {
                    ans[i+1]=x;
                    break;
                }
            }
        }
        return ans;
    }
};
