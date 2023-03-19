class Solution 
{
public:
    vector<int> evenOddBit(int n) 
    {
        int bit=0;
        int even=0;
        int odd=0;
        while(n>0)
        {
            if((n&1)==1)
            {
                if(bit%2==0)
                {
                    even++;
                }
                else
                {
                    odd++;
                }
            }
            bit++;
            n=n>>1;
        }
        return {even,odd};
    }
};
