bool check(int mask,int bit)
{
    int val=mask&(1<<bit);
    return val!=0;
}
void sett(int &mask,int bit)
{
    mask=mask|(1<<bit);
}
void unsett(int &mask,int bit)
{
    mask=mask^(1<<bit);
}
int dp[10][100000];
int dfs(int operation,vector<int>&nums,int mask)
{
    if(operation==nums.size()+1)
    {
        return 0;
    }
    if(dp[operation][mask]!=-1)
    {
        return dp[operation][mask];
    }
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<nums.size();j++)
        {
            if(i==j || check(mask,i)==true || check(mask,j)==true)
            {
                continue;
            }
            sett(mask,i);
            sett(mask,j);
            ans=max(ans,operation*__gcd(nums[i],nums[j])+dfs(operation+1,nums,mask));
            unsett(mask,i);
            unsett(mask,j);
        }
    }
    return dp[operation][mask]=ans;
}
class Solution 
{
public:
    int maxScore(vector<int>& nums) 
    {
        int mask=0;
        memset(dp,-1,sizeof(dp));
        return dfs(1,nums,mask);
    }
};
