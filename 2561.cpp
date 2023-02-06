class Solution 
{
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        #define ll long long
        map<int,ll int>mp;
        for(auto x:basket1)
        {
            mp[x]++;
        }
        for(auto x:basket2)
        {
            mp[x]--;
        }
        
        ll int swap=0;
        ll int ans=0;
        
        for(auto x:mp)
        {
            if(x.second%2!=0)
            {
                return -1;
            }
            swap+=max(0LL,x.second/2);//As for both +ve and -ve same we will do for leat 
            
        }
        for(auto x:mp)
        {
            ll int take=min(swap,abs(x.second)/2);
            ans+=(take*min(x.first,mp.begin()->first*2));
            swap-=take;
        }
        return ans;
    }
};
