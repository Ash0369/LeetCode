#define ll long long
bool check(vector<int>&ranks,int cars,ll int mid)
{
    for(int i=0;i<ranks.size();i++)
    {
        ll int temp=sqrtl(mid/(ranks[i]));
        
        cars=cars-temp;
        if(cars<=0)
        {
            return true;
        }
    }
    return false;
}
class Solution 
{
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        int n=ranks.size();
        sort(ranks.begin(),ranks.end());
        ll int left=1;
        ll int right=1LL*cars*cars*ranks[0];
        cout<<right<<endl;
        ll int ans=right;
        while(left<=right)
        {
            ll int mid=left+((right-left)/2LL);
            if(check(ranks,cars,mid)==true)
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
