int dp2[201][201][201];
int n;
int dfs(int index,int prev,int k,int dp[][205])
{
    if(index==n)
    {
        if(k==0 && prev==n)
        {
            return 0;
        }
        return 1e9;
    }
    if(dp2[index][prev][k]!=-1)
    {
        return dp2[index][prev][k];
    }
    //take or skip it
    int a=dfs(index+1,prev,k,dp);
    
    //take it
    int b=1e9;
    if(k!=0 && prev!=index)
    {
        b=dp[prev][index]+dfs(index+1,index+1,k-1,dp);
    }
    return dp2[index][prev][k]=min(a,b);
}

int check(string &s)
{
    int n=s.size();
    n--;
    int a=0;
    int c=0;
    while(a<n)
    {
        if(s[a]!=s[n])
        {
            c++;
        }
        a++;
        n--;
    }
    return c;
}

int check(string &s,int start,int d,int num)
{
    int r=0;
    for(int offset=0;offset<d;offset++)
    {
        for(int i=start+offset,j=i+d*(num-1);i<j;i+=d,j-=d)
        {
            r+=s[i]!=s[j];
        }
    }
    return r;
}
class Solution 
{
public:
    int minimumChanges(string s, int k) 
    {
        n=s.size();
        int dp[205][205];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=i;j<n;j++)
            {
                //How to make (i,j) as semi palindeome
                temp.push_back(s[j]);
                if(i==j)
                {
                    //cannot make a string of Length 1 as semipalindrome
                    continue;
                }
                
                
                int sz=j-i+1;
                int cnt=sz-1;
                for(int d=1;d*d<=sz;d++)
                {
                    if(sz%d==0)
                    {
                        int num=sz/d;
                        cnt=min(cnt,check(s,i,d,num));
                        
                        if(d!=num && d!=1)
                        {
                            cnt=min(cnt,check(s,i,num,d));
                        }
                    }
                }
                dp[i][j]=cnt;
            }
        }
        memset(dp2,-1,sizeof(dp2));
        return dfs(0,0,k,dp);
    }
};
