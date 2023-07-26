bool check(vector<int>&dist,double hr,int speed)
{
    int n=dist.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        double temp=(double)dist[i]/speed;
        
        if(i==n-1)
        {
            double tot=(double)ans + temp;
            if((hr-tot)>=0.000)
            {
                return true;
            }
        }
        ans+=(dist[i]+speed-1)/speed;
        
    }
    return false;
}
class Solution 
{
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int left=1;
        int right=10000000;
        int ans=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(check(dist,hour,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};
