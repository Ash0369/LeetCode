#define ll long long
class Solution 
{
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<ll int>ans(n,0);
        for(auto x:mp)
        {
            int ele=x.first;
            ll int tot=0;
            for(auto y:x.second)
            {
                tot+=y;
            }
            ll int till=0;
            int cnt=0;
            int rem=x.second.size()-1;
            for(auto y:x.second)
            {
                tot=tot-y;
                ans[y]+=(1LL*cnt*y)-till;
                ans[y]+=(tot)-(1LL*y*rem);
                rem--;
                cnt++;
                till+=y;
            }
        }
        return ans;
    }
};
