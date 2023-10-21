class Solution 
{
public:
    bool checkPerfectNumber(int num) 
    {
        if(num==1)
        {
            return false;
        }
        int ans=0;
        for(int i=1;i*i<=num;i++)
        {
            if(num%i==0)
            {
                ans+=i;
                if(i!=1 && i*i!=num)
                {
                    int r=num/i;
                    ans+=r;
                }
            }
            
        }
        return ans==num;
    }
};
