#define ll long long
int mod=1000000007;
class Solution 
{
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        map<ll int,ll int>mp;
        for(auto x:arr)
        {
            mp[x]++;
        }
        int n=arr.size();
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            int ele=arr[i];
            for(int j=2;j*j<=ele;j++)
            {
                if(ele%j==0)
                {
                    ll int temp=(1LL*mp[j]*mp[ele/j])%mod;
                    
                    if((ele/j)!=j)
                    {
                        temp=(temp*2)%mod;
                    }
                    ans=(ans+temp)%mod;
                    mp[ele]=(mp[ele]+temp)%mod;
                }
            }
        }
        return (ans+n)%mod;
    }
};
