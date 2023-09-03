#define ll long long
int mod=1000000007;
ll int inv(ll int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
ll mod_div(ll a,ll b){return (a*inv(b))%mod;}
class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) 
    {
        int n=s.size();
        vector<int>f(26,0);
        for(auto x:s)
        {
            f[x-'a']++;
        }
        vector<int>v;
        for(int i=0;i<26;i++)
        {
            v.push_back(f[i]);
        }
        sort(v.begin(),v.end());
     
        int fk=k;
        int last=25;
        int p=25;
        ll int s1=1;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(k>0 && v[i]>0)
            {
                s1=(s1*v[i])%mod;
         
                last=v[i];
                p=i;
                k--;
            }
        }
        if(k>0)
        {
            return 0;
        }
        int cnt=0;
        int cnt1=0;
        
        for(int i=0;i<26;i++)
        {
            if(v[i]==last)
            {
                cnt++;
            }
        }
        for(int i=p;i<26;i++)
        {
            if(v[i]==last)
            {
                cnt1++;
            }
        }
        
        ll int f1=1;
        ll int f2=1;
        ll int f3=1;
        for(int i=1;i<=cnt;i++)
        {
            f1=(f1*i)%mod;
        }
        for(int i=1;i<=cnt1;i++)
        {
            f2=(f2*i)%mod;
        }
        for(int i=cnt-cnt1;i>=1;i--)
        {
            f3=(f3*i)%mod;
        }
        ll int ans=inv((f2*f3)%mod);
        ans=(ans*f1)%mod;          
        return (ans*s1)%mod;
        
    }
};
