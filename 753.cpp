//https://www.youtube.com/watch?v=VZvU1_oPjg0&t=1033s
//https://leetcode.com/problems/cracking-the-safe/discuss/1254286/C%2B%2B-Solution

string rel;
bool dfs(string &curr,int total,int n,int k,unordered_set<string>&dp)
{
    if(dp.size()==total)
    {
        rel=curr;
        return true;//For by passing TLE
    }
    string temp=curr.substr(curr.length()-n+1,n-1);
    for(int i=0;i<k;i++)
    {
        char a=i+'0';
        curr.push_back(a);
        temp.push_back(a);
        if(dp.find(temp)!=dp.end())
        {
            curr.pop_back();
            continue;
        }
        dp.insert(temp);
        if(dfs(curr,total,n,k,dp))
           return true;
        dp.erase(temp);
        curr.pop_back();
    }
    return false;
}
class Solution 
{
public:
    string crackSafe(int n, int k) 
    {
        int total=pow(k,n);
        rel.clear();
        string curr="";
        for(int i=0;i<n;i++) 
            curr.push_back('0');
        unordered_set<string>dp;
        dp.insert(curr);
        dfs(curr,total,n,k,dp);
        
        return rel;
    }
};
