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


//Method-2 : Top Down DP O(n) Time Complexity and O(n) Space Complexity and O(n) Auxillary Space Complexity

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

//Method-3 : Bottom Up DP (Removed Recurssion stack space)  O(n) Time Complexity and O(n) Space Complexity

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

//Method-4 : O(1) Space and O(n) Time complexity

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
        int a=0;
        int b=1;
        int c;
        for(int i=2;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
            //We have remove vector space.
        }
        return b;
    }
};


//Method-5 : Binary exponentaion for very large values of n :


vector<vector<int>> mul(vector<vector<int>>matrix1,vector<vector<int>>matrix2)
{
    int x=matrix1[0].size();
    int y=matrix2.size();
    vector<vector<int>>ans;
    for(int i=0;i<matrix1.size();i++)
    {
        vector<int>temp;
        for(int j=0;j<x;j++)
        {
            int sum=0;
            for(int k=0;k<y;k++)
            {
                sum=sum+matrix1[i][k]*matrix2[j][k];
            }
            temp.push_back(sum);
        }
        ans.push_back(temp);
    }
    return ans;
}
vector<vector<int>> matrix_exponentation(vector<vector<int>>matrix , int n)
{
    if(n==0)
    {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                matrix[i][j]=1;
            }
        }
    }
    
    if(n==1)
        return matrix;
     
    auto a=matrix_exponentation(matrix,n/2);
    auto x=mul(a,a);

    if(n%2==0)
    {
        return x;
    }
    return mul(x,matrix);
}

class Solution 
{
public:
    int fib(int n) 
    {
        if(n==0)
            return 0;
        vector<vector<int>>vec;
        vec={{1,1},{1,0}};
        
        auto ans=matrix_exponentation(vec,n);
        return ans[1][0];
    }
};
