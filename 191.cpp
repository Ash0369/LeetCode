class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int a=1;
        int count=0;
        for(int i=0;i<=31;i++)
        {
            a=1<<i;
            if((a&n)>=1)
            {
                count++;
            }
        }
        return count;
    }
    
};
