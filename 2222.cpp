#define ll long long

class Solution 
{
public:
    long long numberOfWays(string s) 
    {
        int n=s.size();
        int z=s[n-1]=='0';
        int o=s[n-1]=='1';
        ll int ans=0;
        ll int cnt0=0;//Number of sequence of 01 from i to n
        ll int cnt1=0;//Number of sequence of 10 from i to n
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                z++;
                cnt0+=o;
                ans+=cnt1;
            }
            else
            {
                o++;
                cnt1+=z;
                ans+=cnt0;
            }
        }
        return ans;
    }
};
