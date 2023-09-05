#define ll long long
class Tree
{
    //Work on zero based indexing
    public:
    vector<vector<int>>dp;
    vector<vector<ll int>>value;
    Tree(int n,vector<int>&rec)
    {
        dp.resize(n+2,vector<int>(50,0));
        value.resize(n+2,vector<ll int>(50,0));
        for(int index=0;index<n;index++)
        {
           dp[index][0]=rec[index];
           value[index][0]=rec[index];
        }
    }
    void make_parent(int n)
    {
        for(int j=1;j<=39;j++)
        {
            for(int i=0;i<n;i++)
            {
                int p=dp[i][j-1];
                ll int v=value[i][j-1];
                dp[i][j]=dp[p][j-1];
                value[i][j]=v+value[p][j-1];
            }
        }
    }
};
class Solution 
{
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) 
    {
        ll int ans=0;
        int n=receiver.size();
        Tree t(n,receiver);
        t.make_parent(n);
        for(int i=0;i<n;i++)
        {
            ll int curr_pos=i;
            ll int curr_value=i;
            
            for(int j=0;j<40;j++)
            {
                if((k&(1LL<<j))>0)
                {
                    curr_value+=t.value[curr_pos][j];
                    curr_pos=t.dp[curr_pos][j];
                } 
            }
            ans=max(ans,curr_value);
        }
        return ans;
    }
};
