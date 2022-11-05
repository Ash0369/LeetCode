//Method-1 : 

class Solution 
{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        #define ll long long
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(auto x:edges)
        {
            dp[x[0]][x[1]]=x[2];
            dp[x[1]][x[0]]=x[2];
        }
        for(int i=0;i<n;i++)
            dp[i][i]=0;
        for(int i=0;i<n;i++)
        {
            for(int row=0;row<n;row++)
            {
                
                for(int col=0;col<n;col++)
                {
                    if(dp[row][i]==INT_MAX || dp[i][col]==INT_MAX)
                        continue;
                    ll int d=dp[row][i]+dp[i][col];
                    if(d<dp[row][col])
                        dp[row][col]=d;
                }
            }
        }
        
        int ans=INT_MAX;
        int city=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && dp[i][j]<=distanceThreshold)
                    cnt++;
            }
            if(cnt<=ans)
            {
                ans=cnt;
                city=i;
            }
        }
        return city;
    }
};


//Method-2 : Adding some continue statemnet to increse speed

class Solution 
{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        #define ll long long
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(auto x:edges)
        {
            dp[x[0]][x[1]]=x[2];
            dp[x[1]][x[0]]=x[2];
        }
        for(int i=0;i<n;i++)
        {
            for(int row=0;row<n;row++)
            {
                if(row==i)
                    continue;
                for(int col=0;col<n;col++)
                {
                    if(col==i)
                        continue;
                    if(row==col)
                        dp[row][row]=0;
                    if(dp[row][i]==INT_MAX || dp[i][col]==INT_MAX)
                        continue;
                    ll int d=dp[row][i]+dp[i][col];
                    if(d<dp[row][col])
                        dp[row][col]=d;
                }
            }
        }
        
        int ans=INT_MAX;
        int city=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && dp[i][j]<=distanceThreshold)
                    cnt++;
            }
            if(cnt<=ans)
            {
                ans=cnt;
                city=i;
            }
        }
        return city;
    }
};
