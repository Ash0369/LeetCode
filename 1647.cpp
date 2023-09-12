class Solution 
{
public:
    int minDeletions(string s) 
    {
        vector<int>dp(26,0);
        for(auto x:s)
        {
            dp[x-'a']++;
        }
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<26;i++)
        {
            if(dp[i]==0)continue;
            mp[dp[i]]++;
        }
        int n=s.size();
        for(int i=n;i>=1;i--)
        {
            if(mp[i]==0)
            {
                continue;
            }
            if(mp[i]>1)
            {
                mp[i-1]+=mp[i]-1;
                ans+=mp[i]-1;
            }
        }
        return ans;
    }
};
