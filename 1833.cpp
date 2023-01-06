class Solution 
{
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(),costs.end());
        int ice=0;
        for(int i=0;i<costs.size();i++)
        {
            if(coins>=costs[i])
            {
                ice++;
                coins-=costs[i];
            }
        }
        return ice;
    }
};
