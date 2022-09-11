class Solution 
{
public:
    bool checkDistances(string s, vector<int>& distance) 
    {
        map<char,vector<int>>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]].push_back(i);
        }
        for(auto x:mp)
        {
            char c=x.first;
            int position=int(c)-97;
            int d=distance[position];
            if((x.second[1]-x.second[0])!=(d+1))
            {
                return false;
            }
        }
        return true;
    }
};
