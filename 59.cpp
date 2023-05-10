class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>>dp(n,vector<int>(n,0));
        int i=0;
        int j=n-1;
        int k=n-1;
        int l=0;
        int curr=1;
        while(i<n && l<n)
        {
            //ith row
            
            for(int a=0;a<n;a++)
            {
                if(dp[i][a]==0)
                {
                    dp[i][a]=curr;
                    curr++;
                }
            }
            
            //jth column
            
            for(int a=0;a<n;a++)
            {
                if(dp[a][j]==0)
                {
                     dp[a][j]=curr;
                     curr++;
                }
            }
            
             //kth row
            
            for(int a=n-1;a>=0;a--)
            {
                if(dp[k][a]==0)
                {
                     dp[k][a]=curr;
                     curr++;
                }
            }
            
             //lth col
            
            for(int a=n-1;a>=0;a--)
            {
                if(dp[a][l]==0)
                {
                     dp[a][l]=curr;
                     curr++;
                }
            }
            
            i++;
            j--;
            k--;
            l++;
        }
        return dp;
    }
};
