//Method-1 : 

#define ll long long
int mod=1e9+7;
int house(int index,int n,bool a,bool b,int dp[][2][2])
{
    if(index>n)
    {
        return 1;
    }
    
    if(dp[index][a][b]!=-1)
    {
        return dp[index][a][b];
    }
    ll int ans1=0;
    ll int ans2=0;
    ll int ans3=0;
    ll int ans4=0;
    //Not place on any side
    ans1=house(index+1,n,false,false,dp);
    
    //place on side but prev should not be placed
    
    if(a==false)
    {
        ans2=house(index+1,n,true,false,dp);
    }
    if(b==false)
    {
        ans3=house(index+1,n,false,true,dp);
    }
    if(a==false && b==false)
    {
        ans4=house(index+1,n,true,true,dp);
    }
    
    return dp[index][a][b]=(ans1+ans2+ans3+ans4)%mod;
    
}
class Solution 
{
public:
    int countHousePlacements(int n) 
    {
        int dp[n+1][2][2];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        return house(1,n,false,false,dp);
    }
};

//Method-2 : 

#define ll long long
int mod=1e9+7;
class Solution 
{
public:
    int countHousePlacements(int n) 
    {
        ll int dp[n+1][2][2];
        
        //dp[i][j][k] represent way to  placed house till ith index
        //such that at ith j,k
        dp[0][0][0]=0;
        dp[0][0][1]=0;
        dp[0][1][0]=0;
        dp[0][1][1]=0;
        for(int i=0;i<n;i++)
        {
            dp[i+1][0][0]=(dp[i][0][0]+dp[i][0][1]+dp[i][1][0]+dp[i][1][1])%mod;
            dp[i+1][1][0]=(1+dp[i][0][0]+dp[i][0][1])%mod;
            dp[i+1][0][1]=(1+dp[i][0][0]+dp[i][1][0])%mod;
            dp[i+1][1][1]=(1+dp[i][0][0])%mod;
            
        }
        return (1+dp[n][0][0]+dp[n][0][1]+dp[n][1][0]+dp[n][1][1])%mod;
    }
};


//Method-3 : 
//https://leetcode.com/problems/count-number-of-ways-to-place-houses/discuss/2198119/House-Robber-2


#define ll long long
int mod=1e9+7;
class Solution 
{
public:
    int countHousePlacements(int n) 
    {
       int placed = 0, empty = 1, res = 1;
       for (int i=1;i<=n;i++) 
       {
           placed=empty;
           empty=res;
           res=(placed+empty)%mod;
       }
       return (1LL*res*res)%mod;
    }
};
