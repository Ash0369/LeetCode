class Solution 
{
public:
    int accountBalanceAfterPurchase(int purchaseAmount) 
    {
        int d=purchaseAmount/10;
        if(purchaseAmount%10!=0)
        {
            if(purchaseAmount%10>=5)
            {
                d++;
            }
        }
        return 100-(10*d);
    }
};
