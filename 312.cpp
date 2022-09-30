//Method-1 : 

int distribute(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
{
    if(i>j)
        return 0;
    
    if(dp[i][j]==-1)
    {
        int ans=0;
        int coin=0;
        for(int index=i;index<=j;index++)
        {
            coin= (nums[i-1]*nums[index]*nums[j+1]) +distribute(i,index-1,nums,dp)+distribute(index+1,j,nums,dp);
            ans=max(ans,coin);
        }
        dp[i][j]=ans;
    }
    return dp[i][j];
}
class Solution 
{
public:
    int maxCoins(vector<int>& nums) 
    {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return distribute(1,n,nums,dp);
    }
};


//Method-2 : 

class Solution 
{
public:
    int maxCoins(vector<int>& nums) 
    {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)//j should be greter
            {
                if(j<i)
                    continue;
                int ans=0;
                int coin=0;
                for(int index=i;index<=j;index++)
                {
                   coin=(nums[i-1]*nums[index]*nums[j+1])+dp[i][index-1] + dp[index+1][j];
                   ans=max(ans,coin);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n];
    }
};
