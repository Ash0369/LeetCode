class Solution 
{
public:
    int countSymmetricIntegers(int low, int high) 
    {
        int ans=0;
        for(int i=low;i<=high;i++)
        {
            int num=i;
            int d=0;
            while(num>0)
            {
                d++;
                num=num/10;
            }
            int s1=0;
            int s2=0;
            if(d%2!=0)
            {
                continue;
            }
            d=d/2;
            num=i;
            int d1=0;
            while(num>0)
            {
                d1++;
                if(d1<=d)
                {
                    s1+=num%10;
                }
                if(d1>d)
                {
                    s2+=num%10;
                }
                num=num/10;
            }
            if(s1==s2)
            {
                ans++;
            }
        }
        return ans;
    }
};
