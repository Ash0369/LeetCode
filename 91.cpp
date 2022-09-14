//Method-1 : Memoization 


int decode(string s,int index,vector<int>&dp)
{
    if(index>=s.size())
        return 1;

    if(s[index]=='0')
    {
        return dp[index]=0;
    }
    else
    {
        if(dp[index]==-1)
        {
            int a=decode(s,index+1,dp);
            dp[index]=a;
            if(index+1<s.length())
            {
                if(s[index]=='2' && s[index+1]<='6')
                    dp[index]= a+decode(s,index+2,dp);
                else if(s[index]=='1')
                    dp[index]= a+decode(s,index+2,dp);
            }
        }
        return dp[index];
        
    }
}
class Solution 
{
public:
    int numDecodings(string s) 
    {
        vector<int>dp(s.length()+1,-1);
        dp[s.length()]=1;
        return decode(s,0,dp);
    }
};


//Method-2 : Tabulation

class Solution 
{
public:
    int numDecodings(string s) 
    {
        vector<int>dp(s.length()+1,-1);
        dp[s.length()]=1;
        
        for(int index=s.length()-1;index>=0;index--)
        {
            int a=dp[index+1];
            dp[index]=a;
            if(s[index]=='0')
            {
                dp[index]=0;
            }
            else if(index+1<s.length())
            {
                
                if(s[index]=='2' && s[index+1]<='6')
                    dp[index]= a+dp[index+2];
                else if(s[index]=='1')
                    dp[index]= a+dp[index+2];
            }
            
        }
        return dp[0];
    }
};
