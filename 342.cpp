//Method-1 : Recursion

class Solution 
{
public:
    bool isPowerOfFour(int n) 
    {
        if(n<=0)
        {
            return false;
        }
        else if(n==1)
        {
            return true;
        }
        else
        {
            if(n%4==0)
            {
                return isPowerOfFour(n/4);
            }
            else
            {
                return false;
            }
        }
    }
};

//Method-2 : Bit Manuplation

class Solution 
{
public:
    bool isPowerOfTwo(int n) 
    {
        long long int x=1;
        for(int i=0;i<=31;i++)
        {
            x=1<<i;
            if(x>n)
            {
                break;
            }
            else if(x==n)
            {
                return true;
            }
        }
        return false;
    }
};
