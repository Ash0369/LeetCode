//Method-1 :

class Solution 
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        map<int,int>mp;
        for(int i=0;i<heights.size();i++)
        {
            mp[heights[i]]=i;
        }
        sort(heights.begin(),heights.end(),greater<int>());
        
        vector<string>ans;
        for(int i=0;i<heights.size();i++)
        {
            ans.push_back(names[mp[heights[i]]]);
        }
        return ans;
    }
};


//Method-2 : 

class Solution 
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        priority_queue<pair<int,string>>pq;
        for(int i=0;i<names.size();i++)
        {
            pq.push({heights[i],names[i]});
        }
        
        vector<string>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
