int mod=1000000007;
#define ll long long
class Solution 
{
public:
    int countHomogenous(string s) 
    {
        ll int ans=0;
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            int c=1;
            i++;
            while(i<n && s[i]==s[i-1])
            {
                i++;
                c++;
            }
            i--;
            
            ans+=(1LL*c*(c+1))/2;
            ans=ans%mod;
        }
        return ans;
    }
};
