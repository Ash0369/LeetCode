#define ll long long
bool banana(vector<int>&piles,int h,ll int k)
{
    ll int tot=0;
    for(int i=0;i<piles.size();i++)
    {
        tot+=((1LL*piles[i]+k-1)/k);
    }
    return tot<=h;
}
class Solution 
{
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        ll int left=1;
        ll int right=piles[n-1];
        ll int ans=right;
        while(left<=right)
        {
            ll int k=(left+right)/2;
            //We have to try with this value of k
            if(banana(piles,h,k))
            {
                right=k-1;
                ans=k;
            }
            else
            {
                left=k+1;
            }
        }
        return ans;
    }
};
