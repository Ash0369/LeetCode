#define ll long long
int pr[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int dp[11][3][22][25][3];
int dfs(int index,string &s,bool tight,int r,int d,int k,bool p)
{
    int n=s.size();
    int pos=n-index-1;
    if(index==s.size())
    {
        return r==0 && d==12;
    }
    if(dp[index][tight][r][d][p]!=-1)
    {
        return dp[index][tight][r][d][p];
    }
    int ans=0;
    int ub=9;
    if(tight==true)
    {
        ub=s[index]-'0';
    }
    for(int dig=0;dig<=ub;dig++)
    {
        //place the dig
        ll int v=1LL*pr[pos]*dig;
        ll int nr=(v+r)%k;
        int x=d;
        if(dig%2==0)
        {
            x++;
        }
        else
        {
            x--;
        }
        if(dig==0 && p==false)
        {
            x=d;
        }
        ans+=dfs(index+1,s,(tight & (dig==ub)),nr,x,k,(p|(dig!=0)));
    }
    return dp[index][tight][r][d][p]=ans;
}
class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        if(k==0) return 0;
        
        int len=to_string(high).size();
        memset(dp,-1,sizeof(dp));
        string h=to_string(high);
        int ans1=dfs(0,h,true,0,12,k,false);
        memset(dp,-1,sizeof(dp));
        h=to_string(low);
        int ans2=dfs(0,h,true,0,12,k,false);
        int ans=ans1-ans2;
        
        if(low%k==0)
        {
            int b=0;
            while(low>0)
            {
                int k=low%10;
                if(k%2==0)
                {
                    b++;
                }
                else
                {
                    b--;
                }
                low=low/10;
            }
            if(b==0)
            {
                ans++;
            }
        }
        return ans; 
    }
};
