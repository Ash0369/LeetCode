#define ll long long
class Solution 
{
public:
    int guessNumber(int n) 
    {
        ll int low=1;
        ll int high=n;
        while(low<=high)
        {
            ll int mid=(low+high)/2;
            ll int res=guess(mid);
            if(res==0)
                return mid;
            else if(res==1)
                low=mid+1;
            else
                high=mid-1;
                
        }
        return -1;
    }
};
