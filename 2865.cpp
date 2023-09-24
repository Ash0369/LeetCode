#define ll long long
class Solution 
{
public:
    long long maximumSumOfHeights(vector<int>& mh) 
    {
        int n=mh.size();
        ll int ans1=0;
        for(int i=0;i<n;i++)
        {
            //considering peak at i
            ll int ans=0;
            ll int prev=mh[i];
            for(int j=i-1;j>=0;j--)
            {
                ll int av=mh[j];
                ll int build=min(av,prev);
                ans+=build;
                prev=build;
            }
            prev=mh[i];
            for(int j=i+1;j<n;j++)
            {
                ll int av=mh[j];
                ll int build=min(av,prev);
                ans+=build;
                prev=build;
            }
            ans1=max(ans1,ans+mh[i]);
        }
        return ans1;
    }
};
