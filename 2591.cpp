class Solution 
{
public:
    int distMoney(int money, int children) 
    {
        if(money<children)
        {
            return -1;
        }
        money=money-children;
        int ans=0;
        while(children>0)
        {
            if(money>=7)
            {
                ans++;
                money=money-7;
            }
            else
            {
                if(money!=3)
                {
                    return ans;
                }
                else
                {
                    if(children>=2)
                    {
                        return ans;
                    }
                    return max(0,ans-1);
                }
            }
            children--;
        }
        if(money==0)
        {
            return ans;
        }
        return ans-1;
        
    }
};
