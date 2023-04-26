class Solution 
{
public:
    int addDigits(int num) 
    {
        if(num/10==0)
        {
            return num;
        }
        int ans=0;
        while(num>0)
        {
            int d=num%10;
            ans=(ans*1)+d;
            num=num/10;
        }
        return addDigits(ans);
    }
};
