#define ll long long
class Solution 
{
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) 
    {
        ll int ans=0;
        for(int i=0;i<k;i++)
        {
            ll int left=0;
            ll int right=1e10;
            
            while(left<=right)
            {
                ll int mid=(left+right)/2;
                ll int b=budget;
                for(int j=0;j<n;j++)
                {
                    ll int need=1LL*mid*composition[i][j];
                    if(need<=stock[j])
                    {
                        continue;
                    }
                    else
                    {
                        ll int p=need-stock[j];
                        b=b-(1LL*p*cost[j]);
                        if(b<0)
                        {
                            break;
                        }
                    }
                }
                if(b>=0)
                {
                    ans=max(ans,mid);
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
        }
        return ans;
    }
};
