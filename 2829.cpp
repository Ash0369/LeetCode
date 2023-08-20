class Solution 
{
public:
    int minimumSum(int n, int k) 
    {
        int sum=0;
        map<int,int>mp;
        int ele=n;
        int x=1;
        while(ele>0)
        {
            if((k-x==x && mp.find(x)==mp.end() ) || mp.find(k-x)==mp.end())
            {
                mp[x]++;
                sum+=x;
                ele--;
            }
            x++;
        }
        return sum;
    }
};
