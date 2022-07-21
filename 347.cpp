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

//Method-1 using map and priority queue and time complexity is O(n)

