//Method-1 : 

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


//Method-2 : 

class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt++;
            int left=i-1;
            int right=i+1;
            while(left>=0 && right<n && s[left]==s[right])
            {
                cnt++;
                left--;
                right++;
            }
            left=i-1;
            right=i;
            while(left>=0 && right<n && s[left]==s[right])
            {
                cnt++;
                left--;
                right++;
            }
        }
        return cnt;
    }
};
