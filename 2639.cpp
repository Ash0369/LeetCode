int len(int n)
{
    if(n==0)
    {
        return 1;
    }
    int ans=0;
    if(n<0)
    {
        ans++;
        n=abs(n);
    }
    while(n>0)
    {
        n=n/10;
        ans++;
    }
    return ans;
}
class Solution 
{
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>ans(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int l=len(grid[i][j]);
                ans[j]=max(ans[j],l);
            }
        }
        return ans;
    }
};
