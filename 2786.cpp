#define ll long long
ll int dfs(int index,vector<int>&nums,vector<ll int>&dp,int x,vector<int>&same,vector<int>&diff)
{
    if(index>=nums.size())
    {
        return 0;
    }
    
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    //move to same or differenr
    
    int index1=same[index];
    int index2=diff[index];
    ll int ans1=nums[index];
    ll int ans2=nums[index];
    if(index1!=-1)
    {
        ans1+=dfs(index1,nums,dp,x,same,diff);
    }
    if(index2!=-1)
    {
        ans2+=dfs(index2,nums,dp,x,same,diff)-x;
    }
    return dp[index]=max(ans1,ans2);
}
class Solution 
{
public:
    long long maxScore(vector<int>& nums, int x) 
    {
        int n=nums.size();
        vector<int>same(n);
        vector<int>diff(n);
        int prevo=-1;
        int preve=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]%2==0)
            {
                same[i]=preve;
                diff[i]=prevo;
                preve=i;
            } 
            else
            {
                same[i]=prevo;
                diff[i]=preve;
                prevo=i;
            }
            
        }
        vector<ll int>dp(n+1,-1);
        return dfs(0,nums,dp,x,same,diff);
    }
};
