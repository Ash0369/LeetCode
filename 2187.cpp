#define ll long long
ll trips(vector<int>&time,ll int ava)
{
    ll int ans=0;
    for(auto &x:time)
    {
        ans+=ava/x;
    }
    return ans;
}
class Solution 
{
public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        sort(time.begin(),time.end());
        int n=time.size();
        ll int left=0;
        ll int right=(1LL*time[n-1]*totalTrips)+5;
        ll int ans=right;
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            ll int find=trips(time,mid);
            if(find<totalTrips)
            {
                left=mid+1;
            }
            else
            {
                ans=mid;
                right=mid-1;
            }
        }
        return ans;
    }
};
