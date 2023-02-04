class Solution 
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int mx=0;
        for(auto x:candies)
        {
            mx=max(mx,x);
        }
        vector<bool>ans;
        for(int i=0;i<candies.size();i++)
        {
            if((candies[i]+extraCandies)>=mx)
            {
                ans.emplace_back(true);
            }
            else
            {
                ans.emplace_back(false);
            }
        }
        return ans;
    }
};
