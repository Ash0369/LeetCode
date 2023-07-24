#define ll long long
class Solution 
{
public:
    int maxIncreasingGroups(vector<int>& usageLimits) 
    {
        ll int tot=0;
        int n=usageLimits.size();
        sort(usageLimits.begin(),usageLimits.end());
        int x=0;
        for(int i=0;i<n;i++)
        {
            ll int need=1LL*(x+1)*(x+2)/2;
            tot+=usageLimits[i];
            if(tot>=need)
            {
                x++;
            }
        }
        return x;
    }
};
