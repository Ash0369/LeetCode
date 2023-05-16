#define ll long long
int ans=0;
int dfs(int index,int n, vector<int>& cost)
{
    if(index>n)
    {
        return 0;
    }
    int i1=2*index;
    int i2=(2*index)+1;
    ll int left=dfs(i1,n,cost);
    ll int right=dfs(i2,n,cost);
    ans+=abs(left-right);
    return max(left,right)+cost[index-1];
}
class Solution 
{
public:
    int minIncrements(int n, vector<int>& cost) 
    {
        #define ll long long
        ans=0;
        dfs(1,n,cost);
        return ans;
    }
};
