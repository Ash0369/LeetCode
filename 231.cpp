//Method-1 : Recursion

class Solution 
{
public:
    bool isPowerOfTwo(int n) 
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
            if(n%2==0)
            {
                return isPowerOfTwo(n/2);
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

//Method-3 : Without Loop

class Solution 
{
public:
    bool isPowerOfTwo(int n) 
    {
        if(n<=0)
        {
            return false;
        }
        if(n==1)
        {
            return true;
        }
        if((n&(n-1))==0  && (n-1)%2==1)
        {
            return true;
        }
        return false;
    }
};
