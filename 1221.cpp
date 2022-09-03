class Solution 
{
public:
    int balancedStringSplit(string s) 
    {
        int count=0;
        int r=0;
        int l=0;
        for(auto x:s)
        {
            if(x=='R')
            {
                r++;
            }
            else
            {
                l++;
            }
            
            if(l==r)
            {
                l=0;
                r=0;
                count++;
            }
        }
        return count;
    }
};
