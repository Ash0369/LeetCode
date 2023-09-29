#define ll long long
class Solution 
{
public:
    long long maximumSumOfHeights(vector<int>& mh) 
    {
        int n=mh.size();
        stack<int>st;
        vector<ll int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()>0 && mh[st.top()]>mh[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                dp[i]=dp[st.top()]+(1LL*mh[i]*(st.top()-i));
            }
            else
            {
                dp[i]=1LL*mh[i]*(n-i);
            }
            st.push(i);
        }
        ll int ans=0;
        stack<int>forw;
        vector<ll int>dp2(n+1,0);
        for(int i=0;i<n;i++)
        {
            while(!forw.empty() && mh[forw.top()]>mh[i])
            {
                forw.pop();
            }
            ll int temp=0;
            if(!forw.empty())
            {
                dp2[i]=dp2[forw.top()]+(1LL*mh[i]*(i-forw.top()));
            }
            else
            {
                dp2[i]=1LL*mh[i]*(i+1);
            }
            ans=max(ans,dp2[i]+dp[i+1]);
            forw.push(i);
        }
        return ans;
    }
};
