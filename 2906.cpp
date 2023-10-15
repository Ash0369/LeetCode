#define ll long long
int mod=12345;
class Solution 
{
public:
    vector<vector<int>>constructProductMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<ll int>>prefix(n+1,vector<ll int>(m+1,1));
        vector<vector<ll int>>suffix(n+1,vector<ll int>(m+1,1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    prefix[i][j]=grid[i][j]%mod;
                    continue;
                }
                if(j>0)
                {
                    prefix[i][j]=(1LL*prefix[i][j-1]*grid[i][j])%mod;
                }
                else
                {
                    prefix[i][j]=(1LL*prefix[i-1][m-1]*grid[i][j])%mod;
                }
                
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                {
                    suffix[i][j]=grid[i][j]%mod;
                    continue;
                }
                if(j<m-1)
                {
                    suffix[i][j]=(suffix[i][j+1]*grid[i][j])%mod;
                }
                else
                {
                    suffix[i][j]=(suffix[i+1][0]*grid[i][j])%mod;
                }
                
            }
        }
        
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
                if(m==1)
                {
                    int x=1;
                    if(i>0)
                    {
                        x=prefix[i-1][0];
                    }
                    int y=1;
                    y=suffix[i+1][0];
                    ans[i].push_back((x*y)%mod);
                    continue;
                }
                if(i==0 && j==0)
                {
                    ans[i].push_back(suffix[i][j+1]);
                }
                else if(i==n-1 && j==m-1)
                {
                    ans[i].push_back(prefix[i][j-1]);
                }
                else if(j==0)
                {
                    ans[i].push_back((prefix[i-1][m-1]*suffix[i][j+1])%mod);
                }
                else if(j==m-1)
                {
                    ans[i].push_back((prefix[i][j-1]*suffix[i+1][0])%mod);
                }
                else
                {
                    ans[i].push_back((prefix[i][j-1]*suffix[i][j+1])%mod);
                }
            }
        }
        return ans;
    }
};
