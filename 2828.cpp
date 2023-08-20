class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans="";
        for(auto x:words)
        {
            ans.push_back(x[0]);
        }
        return ans==s;
    }
};
