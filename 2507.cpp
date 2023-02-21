class Solution 
{
public:
    int smallestValue(int n) 
    {
        while(true)
        {
            int sum=0;
            int iter=2;
            int num=n;
            while(iter<=sqrt(num))
            {
                if(num%iter==0)
                {
                    sum+=iter;
                    num=num/iter;
                }
                else
                {
                    iter++;
                }
            }
            if(num>1)
            {
                sum+=num;
            }
            if(sum==n)
            {
                break;
            }
            n=sum;
        }
        return n;
    }
};
