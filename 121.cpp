class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int cost;
        int minimal=prices[0];
        int max_profit=0;
        for(int i=0;i<n;i++)
        {
            cost=prices[i]-minimal;
            max_profit=max(max_profit,cost);
            minimal=min(prices[i],minimal);
        }
        return max_profit;
    }
};
