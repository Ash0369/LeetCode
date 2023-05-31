class Solution 
{
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        sort(prices.begin(),prices.end());
        int n=prices.size();
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    if(ans>(prices[i]+prices[j]) && money>=(prices[i]+prices[j]))
                    {
                        ans=prices[i]+prices[j];
                    }
                }
            }
        }
        if(ans==1e9)
        {
            return money;
        }
        return money-ans;
    }
};
