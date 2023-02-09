#define ll long long
class Solution 
{
public:
    long long distinctNames(vector<string>& ideas) 
    {
        ll int ans=0;
        unordered_map<int,unordered_set<string>>mp;
        
        for(auto x:ideas)
        {
            mp[x[0]-'a'].insert(x.substr(1));
        }
        
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                ll int mutual=0;
                
                for(auto idea:mp[i])
                {
                    if(mp[j].find(idea)!=mp[j].end())
                    {
                        mutual++;
                    }
                }
                ans+=2LL*(mp[i].size()-mutual)*(mp[j].size()-mutual);//As reverse is also possible so 2 times
            }
        }
        return ans;
    }
};
