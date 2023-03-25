bool check(vector<int>&a,vector<int>&b)
{
    int n1=0;
    int n2=0;
    for(int i=0;i<26;i++)
    {
        if(a[i]>0)
        {
            n1++;
        }
        if(b[i]>0)
        {
            n2++;
        }
    }
    return n1==n2;
}
class Solution 
{
public:
    int numSplits(string s) 
    {
        vector<int>dp(26,0);
        vector<int>curr(26,0);
        for(auto x:s)
        {
            dp[int(x)-97]++;
        }
        int n=s.size();
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            curr[int(s[i])-97]++;
            dp[int(s[i])-97]--;
            if(check(curr,dp))
            {
                ans++;
            }
        }
        return ans;
    }
};
