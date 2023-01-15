#define pii pair<int,string>

bool cmp(pii p1,pii p2)
{
    if(p1.first>p2.first)
        return true;
    if(p1.first<p2.first)
        return false;
    if(p1.second>p2.second)
        return false;
    return true;
}
class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        sort(words.begin(),words.end());
        vector<pair<int,string>>ans;
        map<string,int>mp;
        for(auto x:words)
        {
            mp[x]++;
        }
        for(auto x:mp)
        {
            ans.push_back({x.second,x.first});
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<string>a;
        for(int i=0;i<k;i++)
        {
            a.push_back(ans[i].second);
        }
        return a;
    }
};
