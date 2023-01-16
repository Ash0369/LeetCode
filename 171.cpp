class Solution 
{
public:
    int titleToNumber(string columnTitle) 
    {
        int n=columnTitle.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=int(columnTitle[i])-64;
            ans+=(x)*pow(26,(n-1-i));
        }
        return ans;
    }
};
