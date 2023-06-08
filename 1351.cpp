class Solution 
{
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int ans=0;
        for(auto x:grid)
        {
            int i=lower_bound(x.rbegin(),x.rend(),0)-x.rbegin();
            ans+=i;
        }
        return ans;
    }
};
