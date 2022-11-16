#define ll long long
class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        ll int low=1;
        ll int high=n;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            bool res=isBadVersion(mid);
            
            if(res==true)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
