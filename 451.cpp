class Solution 
{
public:
    string frequencySort(string s) 
    {
        unordered_map<int,int>mp;
        for(auto &c:s)
        {
            mp[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto x:mp)
        {
            pq.push(make_pair(x.second,x.first));
        }
        string res;
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            res=res+string(temp.first,temp.second);
        }
        return res;
    }
};
