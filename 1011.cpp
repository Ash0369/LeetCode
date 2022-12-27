bool ship(int mid,vector<int>&weights,int days)
{
    int n=weights.size();
    int curr=0;
    for(int i=0;i<n;i++)
    {
        if(weights[i]>mid)
            return false;
        curr+=weights[i];
        if(curr>mid)
        {
            days--;
            curr=weights[i];
        }
    }
    if(days<1 || curr>mid)
        return false;
    return true;
}
class Solution 
{
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n=weights.size();
        int left=0;
        int right=0;
        for(int i=0;i<n;i++)
            right+=weights[i];
        
        int ans=right;
        while(left<=right)
        {
            int mid=(left+right)>>1;
            if(ship(mid,weights,days))
            {
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return ans;
    }
};
