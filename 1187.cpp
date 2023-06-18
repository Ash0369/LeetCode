int dp[2005][2005];//index in arr1 , index choosen in arr2 (if nothing then at end)
int dfs(int index,int choose,vector<int>& arr1,vector<int>& arr2)
{
    if(index==arr1.size())
    {
        return 0;
    }
    if(dp[index][choose]!=-1)
    {
        return dp[index][choose];
    }
    int val=-1;
    if(choose!=arr2.size())
    {
        val=arr2[choose];
    }
    else if(choose==arr2.size() && index!=0)
    {
        val=arr1[index-1];
    }
    //Not replace
    int ans1=5000;
    int ans2=5000;
    if(arr1[index]>val)
    {
        ans1=dfs(index+1,arr2.size(),arr1,arr2);
    }
    
    //replace
    int i=upper_bound(arr2.begin(),arr2.end(),val)-arr2.begin();
    if(i<arr2.size())
    {
        ans2=1+dfs(index+1,i,arr1,arr2);
    }
    
    return dp[index][choose]=min(ans1,ans2);
}
class Solution 
{
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) 
    {
        sort(arr2.begin(),arr2.end());
        memset(dp,-1,sizeof(dp));
        int ans=dfs(0,arr2.size(),arr1,arr2);
        cout<<ans<<endl;
        if(ans>=5000)
        {
            return -1;
        }
        return ans;
    }
};
