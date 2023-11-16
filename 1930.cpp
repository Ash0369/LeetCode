class Solution 
{
public:
    int countPalindromicSubsequence(string s) 
    {
        map<char,vector<int>>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]].push_back(i);
        }
        int ans=0;
        int dp[n][26];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[i][s[i]-'a']=1;
            if(i!=0)
            {
                for(int j=0;j<26;j++)
                {
                    dp[i][j]+=dp[i-1][j];
                }
            }
        }
        for(auto x:mp)
        {
            int f=x.second[0];
            int l=x.second[(x.second.size())-1];
            if(f==l)
            {
                continue;
            }
            for(int j=0;j<26;j++)
            {
                int a=dp[l-1][j];
                a=a-dp[f][j]; 
                
                if(a>0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
