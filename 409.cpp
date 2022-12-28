class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        map<char,int>mp;
        for(auto x:s)
            mp[x]++;
        int cnt=0;
        bool odd=false;
        for(auto x:mp)
        {
            if(x.second%2!=0)
            {
                odd=true;
                cnt+=x.second-1;
            }
            else
            {
                cnt+=x.second;
            }
        }
        return cnt+odd;
        
    }
};
