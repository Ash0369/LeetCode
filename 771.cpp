class Solution 
{
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        map<char,int>mp;
        for(auto x:jewels)
        {
            mp[x]++;
        }
        int count=0;
        for(auto x:stones)
        {
            if(mp.find(x)!=mp.end())
            {
                count++;
            }
        }
        return count;
    }
};
