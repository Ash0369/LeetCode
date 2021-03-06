//Method-1 using map and pair and time complexity is O(n*log(n))

class Solution 
{
public:
    vector<int>topKFrequent(vector<int>& nums, int k) 
    {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int>>vec;
        for(auto x:mp)
        {
            vec.push_back(make_pair(x.second,x.first));
        }
        vector<int>result;
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        for(int i=0;i<k;i++)
        {
            result.push_back(vec[i].second);
        }
        return result;
        
    }
};

//Method-2 using map and max priority queue and time complexity is O(n*log(n))

class Solution 
{
public:
    vector<int>topKFrequent(vector<int>& nums, int k) 
    {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto x:mp)
        {
            pq.push(make_pair(x.second,x.first));
        }
        vector<int>result;
        for(int i=0;i<k;i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
        
    }
};

//Method-3 using map and min priority queue and time complexity is O(n*log(k))

class Solution 
{
public:
    vector<int>topKFrequent(vector<int>& nums, int k) 
    {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto x:mp)
        {

            pq.push(make_pair(x.second,x.first));
            if(pq.size()>k)
            {
                pq.pop();
            }  
        }
        vector<int>result;
        for(int i=0;i<k;i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
        
    }
};
