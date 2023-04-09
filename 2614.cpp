bool prime(int n)
{
    if(n==1)
    {
        return false;
    }
    int x=n/2;
    if(x!=1 && n%x==0)
    {
        return false;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
class Solution 
{
public:
    int diagonalPrime(vector<vector<int>>& nums) 
    {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(prime(nums[i][i]))
            {
                ans=max(ans,nums[i][i]);
            }
            if(prime(nums[i][n-1-i]))
            {
                ans=max(ans,nums[i][n-1-i]);
            }
        }
        return ans;
    }
};
