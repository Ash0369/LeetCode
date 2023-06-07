#define ll long long
class Solution 
{
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int>r(n,0);
        vector<int>c(n,0);
        int rc=0;
        int cc=0;
        ll int ans=0;
        for(int i=queries.size()-1;i>=0;i--)
        {
            int type=queries[i][0];
            int y=queries[i][1];
            int val=queries[i][2];
            if(type==0)
            {
                if(r[y]==1)
                {
                    continue;
                }
                r[y]=1;
                
                ans+=(n-cc)*val;
                rc++;
            }
            else
            {
                if(c[y]==1)
                {
                    continue;
                }
                c[y]=1;
                
                ans+=(n-rc)*val;
                cc++;
            }
            
        }
        return ans;
    }
};
