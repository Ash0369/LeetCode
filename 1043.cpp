//Method-1 : 

int partition(vector<int>&arr,int index,int k,vector<int>&dp)
{
    if(index==arr.size())
        return 0;
    if(dp[index]==-1)
    {
        int max_value=0;
        int counter=0;
        int res=INT_MIN;
        for(int i=index;i<arr.size() && counter<k;i++)
        {
            counter++;
            max_value=max(max_value,arr[i]);
            int sum=(max_value*counter) + partition(arr,i+1,k,dp);
            res=max(sum,res);
        }
        dp[index]=res;
    }
    return dp[index];
}
class Solution 
{
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return partition(arr,0,k,dp);
    }
};

//Method-2 : 

class Solution 
{
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<int>dp(n+1,0);
        
        for(int index=n-1;index>=0;index--)
        {
            int max_value=0;
            int counter=0;
            int res=INT_MIN;
            for(int i=index;i<arr.size() && counter<k;i++)
            {
                counter++;
                max_value=max(max_value,arr[i]);
                int sum=(max_value*counter) + dp[i+1];
                res=max(sum,res);
            }
            dp[index]=res;
        }
        return dp[0];
    }
};
