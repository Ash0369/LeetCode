#define pii pair<int,string>

bool cmp(pii p1,pii p2)
{
    if(p1.first>p2.first)
        return true;
    if(p1.first<p2.first)
        return false;
    if(p1.second<p2.second)
        return false;
    return true;
}
class Solution 
{
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) 
    {
        map<string,int>mp;
        int n=senders.size();
        
        for(int i=0;i<n;i++)
        {
            char c=' ';
            mp[senders[i]]+=count(messages[i].begin(),messages[i].end(),c)+1;
        }
        
        vector<pair<int,string>>vec;
        for(auto x:mp)
        {
            vec.push_back({x.second,x.first});
        }
        sort(vec.begin(),vec.end(),cmp);
       // cout<<vec[1].second<<endl;
        return vec[0].second;
    }
};
