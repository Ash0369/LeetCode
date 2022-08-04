//Metod-1 : Brute Force

class Solution 
{
public:
    int fib(int n) 
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        return fib(n-1)+fib(n-2);
    }
};


//Method-2 : Top Down DP

int fibonacci(int n,vector<int>&vec)
{
    if(n==1)
    {
        return 1;
    }
    if(n<=0)
    {
        return 0;
    }
    if(vec[n-2]==-1)
    {
        vec[n-2]=fibonacci(n-2,vec);
    }
    if(vec[n-1]==-1)
    {
        vec[n-1]=fibonacci(n-1,vec);
    }
     vec[n]=vec[n-1]+vec[n-2];
    return vec[n];

}
class Solution 
{
public:
    int fib(int n) 
    {
        vector<int>vec(n+1,-1);
        return fibonacci(n,vec);
    }
};

//Method-3 : Bottom Up DP (Removed Recurssion stack space)

class Solution 
{
public:
    int fib(int n) 
    {
        if(n==0)
        {
            return 0;
        }
        vector<int>vec(n+1,-1);
        vec[0]=0;
        vec[1]=1;
        for(int i=2;i<=n;i++)
        {
            vec[i]=vec[i-1]+vec[i-2]; //We have remove recurssion stack space.
        }
        return vec[n];
    }
};
