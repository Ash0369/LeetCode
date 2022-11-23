class Solution 
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        int n=nums.size();
        vector<int>result(n,0);
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            for(auto x:mp[ele])
            {
                result[x]=i-(mp[ele].size()-1);
            }
        }
        return result;
        
    }
};
