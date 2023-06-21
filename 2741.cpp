int mod=1e9+7;
int n;
int table[15][15][32768];
int way(int index,vector<int>&nums,int dp,int last)
{
    if(index==n)
    {
        return 1;
    }
    if(table[index][last][dp]!=-1)
    {
        return table[index][last][dp];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x=nums[i];
        int l=0;
        if(last!=n)
        {
            l=nums[last];
        }
        if(l==0 || x%l==0 || l%x==0)
        {
            int bit=dp>>i;
            if((bit&1)==1)
            {
                continue;
            }
            dp=dp|(1<<i);
            ans=(ans+way(index+1,nums,dp,i))%mod;
            dp=dp&(~(1<<i));
        }
    }
    return table[index][last][dp]=ans;
}
class Solution 
{
public:
    int specialPerm(vector<int>& nums) 
    {
        n=nums.size();
        memset(table,-1,sizeof(table));
        return way(0,nums,0,n);
    }
};
