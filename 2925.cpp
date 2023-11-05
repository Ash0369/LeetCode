#define ll long long

ll int dfs(int index,int parent,vector<int>& values,vector<vector<int>>&tree)
{
    //Either remove index or below
    ll int ans1=values[index];
    ll int ans2=0;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        ans2+=dfs(x,index,values,tree);
    }
    if(ans2==0)
    {
        return ans1;
    }
    return min(ans1,ans2);
}
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) 
    {
        int n=values.size();
        vector<vector<int>>tree(n);
        for(auto x:edges)
        {
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        ll int tot=0;
        for(auto x:values)
        {
            tot+=x;
        }
        tot=tot-dfs(0,-1,values,tree);
        return tot;
    }
};
