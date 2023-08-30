#define ll long long
class Solution 
{
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        int n=nums.size();
        int mn=1e9;
        ll int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>mn)
            {
                //break it into smaller part
                if(nums[i]%mn==0)
                {
                    ans+=(nums[i]/mn)-1;
                }
                else
                {
                    int a=nums[i]/mn;
                    mn=min(mn,nums[i]/(a+1));
                    ans+=a;
                }
            }
            mn=min(mn,nums[i]);
            //cout<<ans<<" "<<mn<<endl;
        }
        return ans;
    }
};
