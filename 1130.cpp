int maxele(int left,int right,vector<int>&arr)
{
    int ans=0;
    for(int i=left;i<=right;i++)
    {
        ans=max(ans,arr[i]);
    }
    return ans;
}
int leaf(int left,int right,vector<int>& arr,vector<vector<int>>&dp)
{
    if(left==right)
        return 0;
    if(dp[left][right]!=-1)
        return dp[left][right];
    int mn=INT_MAX;
    for(int i=left;i<=(right-1);i++)
    {
        int ele1=maxele(left,i,arr);
        int ele2=maxele(i+1,right,arr);
        
        int v1=leaf(left,i,arr,dp);
        int v2=leaf(i+1,right,arr,dp);
        
        int ans=(ele1*ele2)+v1+v2;
        
        mn=min(mn,ans);
    }
    return dp[left][right]=mn;
}
class Solution 
{
public:
    int mctFromLeafValues(vector<int>& arr) 
    {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return leaf(0,n-1,arr,dp);
    }
};
