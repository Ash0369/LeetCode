#define ll long long
class Solution 
{
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) 
    {
        unordered_map<int,pair<int,int>>mp;
        int n=s.size();
        int ul=1e9;
        for(int i=n-1;i>=0;i--)
        {
            ll int curr=0;
            int j=i;
            int cnt=0;
            while(j>=0 && curr<1e9)
            {
                if(s[j]=='1')
                {
                    curr+=(1<<cnt);
                    mp[curr]={j,i};
                }
                else
                {
                    mp[0]={j,j};
                }
                cnt++;
                j--;
                if(cnt>31)
                {
                    break;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto x:queries)
        {
            int num=x[0]^x[1];
            if(mp.find(num)==mp.end())
            {
                ans.push_back({-1,-1});
            }
            else
            {
                ans.push_back({mp[num].first,mp[num].second});
            }
        }
        return ans;
    }
};
