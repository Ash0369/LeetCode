class Solution 
{
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<vector<int>>ans;
        for(auto x:arr)
        {
            ans.push_back({__builtin_popcount(x),x});
        }
        sort(ans.begin(),ans.end());
        vector<int>a;
        for(auto x:ans)
        {
            a.push_back(x[1]);
        }
        return a;
    }
};
