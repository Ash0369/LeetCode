#define ll long long
class Solution 
{
public:
    long long beautifulSubarrays(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>vec(25,0);
        map<vector<int>,int>mp;
        ll int ans=0;
        mp[vec]++;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            int pos=0;
            while(num>0)
            {
                if((num&1)==1)
                {
                    vec[pos]=(vec[pos]+1)%2;
                }
                num=num>>1;
                pos++;
            }
            mp[vec]++;
            
        }
        for(auto x:mp)
        {
            ll int cnt=x.second;
            ans+=(cnt*(cnt-1))/2;
        }
        return ans;
    }
};
