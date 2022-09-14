int count(int n,char c, map<pair<int,char>,int>&mp)
{
    if(n==0)
    {
        return 1;
    }
    if(mp.find(make_pair(n,c))==mp.end())
    {
        int sum=0;
        vector<char>vec= {'a','e','i','o','u'};
        for(auto x:vec)
        {
            if(x<=c)
            {
                sum=sum+count(n-1,x,mp);
            }
            else
                break;
        }
        mp[make_pair(n,c)]=sum;
    }
    return mp[make_pair(n,c)];
}
class Solution 
{
public:
    int countVowelStrings(int n) 
    {
        map<pair<int,char>,int>mp;
        return count(n,'z',mp);
    }
};
