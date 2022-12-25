class Solution 
{
public:
    bool hasAlternatingBits(int n) 
    {
        bool last;
        if(n%2==0)
        {
            //even
            last=true;
        }
        else
        {
            last=false;
        }
        while(n>0)
        {
            int res=(n&1);
            if(res==1)
            {
                if(last==true)
                    return false;
                last=true;
            }
            else
            {
                if(last==false)
                    return false;
                last=false;
            }
            n=n>>1;
        }
        return true;
    }
};
