class Solution 
{
public:
    int differenceOfSum(vector<int>& nums) 
    {
        int s1=0;
        int s2=0;
        for(auto x:nums)
        {
            s1+=x;
            while(x>0)
            {
                s2+=(x%10);
                x=x/10;
            }
        }
        return abs(s1-s2);
    }
};
