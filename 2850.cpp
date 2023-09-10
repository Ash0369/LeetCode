int dfs(int index,vector<vector<int>>&v,map<pair<int,int>,vector<vector<int>>>&mp,vector<vector<int>>&f)
{
    if(index==v.size())
    {
        return 0;
    }
    int x=v[index][0];
    int y=v[index][1];
    int ans=500;
    for(auto x:mp[{x,y}])
    {
        if(f[x[0]][x[1]]>0)
        {
            f[x[0]][x[1]]--;
            ans=min(ans,x[2]+dfs(index+1,v,mp,f));
            f[x[0]][x[1]]++;
        }
    }
    return ans;
}
class Solution 
{
public:
    int minimumMoves(vector<vector<int>>& grid) 
    {
        int ans=0;
        vector<vector<int>>v;
        vector<vector<int>>f(3,vector<int>(3,0));
        map<pair<int,int>,vector<vector<int>>>mp;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int i1=0;i1<3;i1++)
                    {
                        for(int j1=0;j1<3;j1++)
                        {
                            if(grid[i1][j1]>1)
                            {
                                int d=abs(i-i1)+abs(j-j1);
                                mp[{i,j}].push_back({i1,j1,d});
                            }
                        }
                    }
                    v.push_back({i,j});
                }
                else
                {
                    f[i][j]=grid[i][j]-1;
                }
            }
        }
        return dfs(0,v,mp,f);
    }
};
