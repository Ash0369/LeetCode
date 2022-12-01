#define ll long long
class Solution 
{
public:
    int countPairs(vector<int>& deliciousness) 
    {
        ll int cnt=0;
        ll int mod=1e9+7;
        map<ll int,ll int>mp;
        for(auto x:deliciousness)
            mp[x]++;
        for(auto x:mp)
        {
            int val=x.first;
            for(int i=0;i<=22;i++)
            {
                ll int sum=pow(2,i);
                ll int need=sum-val;
                
                if(mp.find(need)!=mp.end())
                {
                    if(need!=val)
                    {
                        cnt=(cnt+(mp[need]*mp[val]));
                    }
                    else
                    {
                        ll int a=(mp[need]*(mp[need]-1)/2);
                        ll int temp=(a);
                        cnt=(cnt+2*temp);
                        //We have multiplied temp by 2 because if we see the case of need!=val 
                        //There every thing will be counted twice (1->3) then (3->1) so in final we will divide by 2.
                        //so following that we have multiplied here by 2.
                    }
                }
            }
        }
        return (cnt/2)%mod;
    }
};
