//Method-1 : Top Down Approach Time Complexity O(n) , Space Complexity O(n) , Auxillary Space Complexity O(n)

int step=0;
int climb(int n,int curr,vector<int>&vec)
{
    if(curr>n)
    {
        return 0;
    }
    if(curr==n)
    {
        return 1;
    }
    
    if(vec[curr+1]==-1)
    {
        vec[curr+1] =climb(n,curr+1,vec);
    }
    if(vec[curr+2]==-1)
    {
        vec[curr+2]=climb(n,curr+2,vec);
    }
    vec[curr]=vec[curr+1]+vec[curr+2];
    return vec[curr];
}
class Solution 
{
public:
    int climbStairs(int n) 
    {
        vector<int>vec(n+3,-1);
        return climb(n,0,vec);
    }
};

//Method-2 : Bottom Up Approach, Time Complexity O(n) , Space Complexity O(n)

class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n==1)
        {
            return 1;
        }
        vector<int>ways(n+1,0);
        ways[1]=1; //No of ways to reach 1st stair
        ways[2]=2; //No of ways to reach 2nd stair
        for(int i=3;i<=n;i++)
        {
            ways[i]=ways[i-1]+ways[i-2];
        }
        return ways[n];
    }
};

//Method-3 Time Complexity O(n) , Space Complexity O(1)

class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n==1)
        {
            return 1;
        }
        int a=1; //No of ways to reach 1st stair
        int b=2; //No of ways to reach 2nd stair
        for(int i=3;i<=n;i++)
        {
            int c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};
