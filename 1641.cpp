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
