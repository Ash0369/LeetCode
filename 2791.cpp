#define ll long long

unordered_map<int,int>mp;
ll int dfs(int index,int parent,vector<vector<vector<int>>>&tree,int sum)
{
    ll int ans=0;
    if(index!=0)
    {
        for(int i=1<<25;i>0;i=i>>1)
        {
            ans+=mp[sum^i];
        }
        ans+=mp[sum];
        mp[sum]++;
    }
    for(auto x:tree[index])
    {
        if(x[0]==parent)
        {
            continue;
        }
        int new_sum=sum^(1<<(x[1]-'a'));
        ans+=dfs(x[0],index,tree,new_sum);
    }
    return ans;
}
class Solution 
{
public:
    long long countPalindromePaths(vector<int>& parent, string s) 
    {
        mp.clear();
        mp[0]=1;
        int n=parent.size();
        vector<vector<vector<int>>>tree(n+1);
        for(int i=1;i<n;i++)
        {
            tree[parent[i]].push_back({i,s[i]});
        }
        return dfs(0,-1,tree,0);
    }
};
