//Method-1 : 

int count(int n,char c, map<pair<int,char>,int>&mp)
{
    if(n==0)
    {
        return 1;
    }
    if(mp.find(make_pair(n,c))==mp.end())
    {
        int sum=0;
        vector<char>vec= {'a','e','i','o','u'};
        for(auto x:vec)
        {
            if(x<=c)
            {
                sum=sum+count(n-1,x,mp);
            }
            else
                break;
        }
        mp[make_pair(n,c)]=sum;
    }
    return mp[make_pair(n,c)];
}
class Solution 
{
public:
    int countVowelStrings(int n) 
    {
        map<pair<int,char>,int>mp;
        return count(n,'z',mp);
    }
};


//Method-2 : 


int count(int n,char c, vector<vector<int>>&dp)
{
    if(n==0)
    {
        return 1;
    }
    if(dp[n][int(c)]==-1)
    {
        int sum=0;
        vector<char>vec= {'a','e','i','o','u'};
        for(auto x:vec)
        {
            if(x<=c)
            {
                sum=sum+count(n-1,x,dp);
            }
            else
                break;
        }
        dp[n][int(c)]=sum;
    }
    return dp[n][int(c)];
}
class Solution 
{
public:
    int countVowelStrings(int n) 
    {
        vector<vector<int>>dp(n+1,vector<int>(123,-1));
        return count(n,'z',dp);
    }
};


//Method-3 : Optimized Memoization

int count(int n,int c,vector<vector<int>>&dp)
{
    if(n==0)
    {
        return 1;
    }
    if(dp[n][c]==-1)
    {
        int sum=0;
        vector<char>vec= {'a','e','i','o','u'};
        for(int j=0;j<5;j++)
        {
            if(j<=c)
            {
                sum=sum+count(n-1,j,dp);
            }
            else
                break;
        }
        dp[n][c]=sum;
    }
    return dp[n][c];
}
class Solution 
{
public:
    int countVowelStrings(int n) 
    {
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        return count(n,4,dp);   
    }
};

//Method-4 : Tabulation 

class Solution 
{
public:
    int countVowelStrings(int n) 
    {
        vector<vector<int>>dp(n+1,vector<int>(5,0));        
        for(int c=0;c<5;c++)
        {
            dp[0][c]=1;
        }
        vector<char>vec= {'a','e','i','o','u'};
        for(int i=1;i<=n;i++)
        {
            for(int c=0;c<5;c++)
            {
                int sum=0;
                for(int j=0;j<5;j++)
                {
                    if(j<=c)
                    {
                        sum=sum+dp[i-1][j];
                    }
                    else
                        break;
                }
                dp[i][c]=sum;
            }
        }
        return dp[n][4];
    }
};


//Method-5 : Space Optimization

class Solution 
{
public:
    int countVowelStrings(int n) 
    {
        vector<int>dp(5,0);
        vector<int>prev(5,0);
        for(int c=0;c<5;c++)
        {
            dp[c]=1;
            prev[c]=1;
        }
        vector<char>vec= {'a','e','i','o','u'};
        for(int i=1;i<=n;i++)
        {
            for(int c=0;c<5;c++)
            {
                int sum=0;
                for(int j=0;j<5;j++)
                {
                    if(j<=c)
                    {
                        sum=sum+dp[j];
                    }
                    else
                        break;
                }
                prev[c]=sum;
            }
            dp=prev;
        }
        return dp[4];
    }
};


//Method-6 : 

class Solution 
{
public:
    int countVowelStrings(int n) 
    {
        int a=1,e=1,i=1,o=1,u=1;
        
        for(int j=2;j<=n;j++)
        {
            a=a+e+i+o+u;
            e=e+i+o+u;
            i=i+o+u;
            o=o+u;
        }
        return a+e+i+o+u;
    }
    
 };
