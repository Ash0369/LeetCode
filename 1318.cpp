class Solution 
{
public:
    int minFlips(int a, int b, int c) 
    {
        int ans=0;
        while(c>0 || a>0 || b>0)
        {
            int cl=c&1;
            int al=a&1;
            int bl=b&1;
            
            if(cl==1)
            {
                if(al==0 && bl==0)
                {
                    ans++;
                }
            }
            else
            {
                if(al==1)
                {
                    ans++;
                }
                if(bl==1)
                {
                    ans++;
                }
            }
            c=c>>1;
            a=a>>1;
            b=b>>1;
        }
        return ans;
    }
};
