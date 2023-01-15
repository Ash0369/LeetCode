class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            cnt++;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                cnt++;
            }
        }
        
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                if(s[i]==s[i+len-1] && dp[i+1][i+len-2]==1)
                {
                    dp[i][i+len-1]=1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
