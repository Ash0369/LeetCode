void dfs(int index,string &digits,vector<string>&ans,string s,map<int,vector<char>>&mp)
{
    if(index==digits.size())
    {
        if(s!="")
        {
            ans.push_back(s);
        }
        
    }
    for(auto x:mp[digits[index]-'0'])
    {
        s.push_back(x);
        dfs(index+1,digits,ans,s,mp);
        s.pop_back();
    }
}
class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        map<int,vector<char>>mp;
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        
        vector<string>ans;
        dfs(0,digits,ans,"",mp);
        return ans;
    }
};
