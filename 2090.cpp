#define ll long long
class Solution 
{
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<ll int>prefix(n+1,0);
        vector<ll int>suffix(n+1,0);
        
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            if(i-k<=0)
            {
                prefix[i]=nums[i]+prefix[i-1];
            }
            else
            {
                prefix[i]=nums[i]+prefix[i-1]-nums[i-k-1];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(i+k>=n-1)
            {
                suffix[i]=nums[i]+suffix[i+1];
            }
            else
            {
                suffix[i]=nums[i]+suffix[i+1]-nums[i+k+1];
            }
        }
        
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            if(i-k<0 || i+k>=n)
            {
                continue;
            }
            ans[i]=(prefix[i]+suffix[i]-nums[i])/(k+k+1);
        }
        return ans;
    }
};
