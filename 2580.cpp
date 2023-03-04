int mod=1e9+7;
#define ll long long
ll int pwr(ll int a,ll int b)
{
    if(b==0)
        return 1;
    if(b%2==0){ll int ans1=pwr(a,b/2);ll int ans2=(ans1*ans1)%mod;return ans2;}
    ll int ans1=pwr(a,b/2);ll int ans2=(ans1*ans1)%mod;
    ans2=(ans2*a)%mod;
    return ans2;
}
bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[0]<v2[0])
    {
        return true;
    }
    if(v1[0]==v2[0] && v1[1]<v2[1])
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    int countWays(vector<vector<int>>& ranges) 
    {
        int n=ranges.size();
        if(n==1)
        {
            return 2;
        }
        sort(ranges.begin(),ranges.end(),cmp);
        int left=ranges[0][0];
        int right=ranges[0][1];
        int cnt=1;
        int group=0;
        for(int i=1;i<n;i++)
        {
            if(ranges[i][0]<=right)
            {
                cnt++;
                right=max(right,ranges[i][1]);
            }
            else
            {
                group++;
                cnt=1;
                right=ranges[i][1];
            }         
        }
        group++;
        cout<<group<<endl;
        return pwr(2,group);
    }
};
