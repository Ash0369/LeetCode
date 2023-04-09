#define ll long long
class Solution 
{
public:
    vector<long long> getDistances(vector<int>& arr) 
    {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
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
