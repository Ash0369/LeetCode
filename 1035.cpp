int dfs(vector<int>& nums1,vector<int>& nums2,int n,int m,int last,int index,vector<vector<int>>&dp)
{
    if(index==n)
    {
        return 0;
    }
    
    if(last==-1)
    {
        if(dp[index][m+2]!=-1)
        {
            return dp[index][m+2];
        }
    }
    else
    {
        if(dp[index][last]!=-1)
        {
            return dp[index][last];
        }
    }
    //for every index 2 option either connect or not connect
    
    int ans1=dfs(nums1,nums2,n,m,last,index+1,dp);//not connect
    int to=-1;
    int ans2=0;
    for(int i=last+1;i<m;i++)
    {
        if(nums1[index]==nums2[i])
        {
            to=i;
            break;
        }
    }
    if(to!=-1)
    {
        ans2=1+dfs(nums1,nums2,n,m,to,index+1,dp);//onnect
    }
    int ans=max(ans1,ans2);
    if(last==-1)
    {
        return dp[index][m+2]=ans;
    }
    return dp[index][last]=ans;
    
}
class Solution 
{
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>near(n,-2);
        
        for(int i=0;i<n;i++)
        {
            for(int j=min(m-1,i);j>=0;j--)
            {
                if(nums1[i]==nums2[j])
                {
                    near[i]=j;
                    break;
                }
            }
            if(near[i]==-2)
            {
                for(int j=i+1;j<m;j++)
                {
                    if(nums1[i]==nums2[j])
                    {
                        near[i]=j;
                        break;
                    }
                }
            }
        }
        vector<vector<int>>dp(n,vector<int>(m+3,-1));
        return dfs(nums1,nums2,n,m,-1,0,dp);
    }
};
