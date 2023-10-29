#define ll long long
class Solution 
{
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size();
        int n2=nums2.size();
        ll int cur1=0;
        int z1=0;
        ll int cur2=0;
        int z2=0;
        for(auto x:nums1)
        {
            cur1+=x;
            if(x==0)
            {
                z1++;
            }
        }
        for(auto x:nums2)
        {
            cur2+=x;
            if(x==0)
            {
                z2++;
            }
        }
        ll int left=max(cur1,cur2);
        ll int right=1e18;
        ll int ans=1e18;
        
        if(z1==0 && z2==0)
        {
            if(cur1==cur2)
            {
                return cur1;
            }
            return -1;
        }
        if(z1==0)
        {
            if(cur1>=cur2+z2)
            {
                return cur1;
            }
            return -1;
        }
        if(z2==0)
        {
            if(cur1+z1<=cur2)
            {
                return cur2;
            }
            return -1;
        }
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            
            ll int tot1=cur1+z1;
            ll int tot2=cur2+z2;
            if(mid>=tot1 && mid>=tot2)
            {
                ans=min(ans,mid);
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        if(ans==1e18)
        {
            return -1;
        }
        return ans;
    }
};
