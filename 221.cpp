class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int dp[m+1][n+1];
        //dp[i][j] denoted largest square that filled with 1 and end at i,j
        dp[0][0]=0;
        dp[0][1]=0;
        dp[1][0]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //Take square ending at i-1,j-1 and extend
                //Form new square
                if(matrix[i-1][j-1]=='0')
                {
                    dp[i][j]=0;
                    continue;
                }
                if(i==1 || j==1)
                {
                    dp[i][j]=1;
                    continue;
                }
      
                int a=dp[i-1][j];
                int b=dp[i][j-1];
                int c=dp[i-1][j-1];
                
                dp[i][j]=1+min(a,min(b,c));
                
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }
        ans=pow(ans,2);
        return ans;
    }
};
