class Solution 
{
public:
    int minimumCost(vector<int>& cost) 
    {
        int n=cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        int price=0;
        for(int i=0;i<n;i++)
        {
            price+=cost[i];
            i++;
            if(i<n)
            {
                price+=cost[i];
                i++;
            }
        }
        return price;
    }
};
