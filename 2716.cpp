class Solution {
public:
    int minimizedStringLength(string s) {
        map<char,int>mp;
        for(auto x:s)
        {
            mp[x]++;
        }
        return mp.size();
    }
};
