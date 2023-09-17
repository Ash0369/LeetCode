#define ll long long
class Solution 
{
public:
    long long maximumSum(vector<int>& nums) 
    {
        ll int ans=0;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            ll int sum=0;
            sum=nums[i-1];
            for(int j=i+1;j<=n;j++)
            {
                ll int r=j*j;
                if((r%i!=0))
                {
                    continue;
                }
                ll int d=r/i;
                if(d>n)
                {
                    break;
                }
                if(d<=n && d>i)
                {
                    sum+=nums[d-1];
                }
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};
