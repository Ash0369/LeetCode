#define ll long long
class Solution 
{
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) 
    {
        int n=nums.size();
        map<ll int,ll int>mp;
        int inf=-2e9;
        mp[inf]=inf;
        
        for(int i=0;i<n;i++)
        {
            auto it=mp.upper_bound(nums[i]-i);
            it--;
            
            ll int new_val=max(nums[i]*1LL,nums[i]+(*it).second);
            
            vector<ll int>erase;
            
            for(it=mp.lower_bound(nums[i]-i);it!=mp.end();it++)
            {
                if((*it).second<=new_val)
                {
                    erase.push_back(it->first);
                }
                else{
                    break;
                }
            }
            for(auto x:erase)
            {
                mp.erase(x);
            }
            if(mp.find(nums[i]-i)==mp.end())
            {
                mp[nums[i]-i]=new_val;
            }
        }
        ll int ans=-2e9;
        
        for(auto &x:mp)
        {
            if(x.first!=inf)
            {
                ans=max(ans,x.second);
            }
        }
        return ans;
    }
};
