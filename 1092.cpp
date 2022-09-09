class Solution 
{
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        //Firstwe find LCS , then with dp grid of LCS we can generate SCS
        
        int n1=str1.length();
        int n2=str2.length();
        
        
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                       dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    int a=0;
                    int b=0;
                    a=dp[i-1][j];
                    b=dp[i][j-1];
                    dp[i][j]=max(a,b);
                }
             }
        }
        
        //We got dp Array
        
        //Now generate SCS from it
        
        int len=dp[n1][n2];
        string ans="";
        
        int index=len-1;
        int i=n1;
        int j=n2;
        
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans=ans+str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) //i-->n1 and j-->n2
            {
                ans=ans+str1[i-1];
                i--;
            }
            else
            {
                ans=ans+str2[j-1];
                j--;
            }
        }
        while(i>0)
        {
            ans=ans+str1[i-1];
            i--;
        }
        
        while(j>0)
        {
            ans=ans+str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
