#define ll long long
bool check(ll int k,int mid,vector<int>&candies)
{
    if(mid==0)
    {
        return true;
    }
    for(int i=0;i<candies.size();i++)
    {
        k=k-(candies[i]/mid);
    }
    return k<=0;
}
class Solution 
{
public:
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int mx=0;
        for(auto x:candies)
        {
            mx=max(x,mx);
        }
        int left=0;
        int right=mx;
        int ans=left;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(check(k,mid,candies))
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};
