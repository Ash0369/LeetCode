#define ll long long

bool check(ll int mid,vector<int>& pt, vector<int>& tasks)
{
    int n=pt.size();
    int z=4*n;
    int j=0;
    for(int i=0;i<z;i=i+4)
    {
        ll int tme=pt[j]+tasks[i];
        j++;
        if(tme<=mid)
        {
            continue;
        }
        return false;
    }
    return true;
}
class Solution 
{
public:
    int minProcessingTime(vector<int>& pt, vector<int>& tasks) 
    {
        int n=pt.size();
        int z=4*n;
        sort(pt.begin(),pt.end());
        sort(tasks.begin(),tasks.end());
        
        reverse(tasks.begin(),tasks.end());
        
        ll int left=0;
        ll int right=1e15;
        int ans=right;
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            if(check(mid,pt,tasks))
            {
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            
        }
        return ans;
    }
};
