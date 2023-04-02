#define ll long long
class Solution 
{
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<ll int>need;
        for(auto x:potions)
        {
            ll int v=success/x;
            if(success%x!=0)
            {
                v++;
            }
            need.push_back(v);
        }
        sort(need.begin(),need.end());
        vector<int>ans;
        for(auto x:spells)
        {
            auto ind=upper_bound(need.begin(),need.end(),x);
            ll int ele=(ind-need.begin());
            ans.push_back(ele);
        }
        return ans;
    }
};
