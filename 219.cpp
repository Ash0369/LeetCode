class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int left=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                int d=i-mp[nums[i]];
                if(d<=k)
                    return true;
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};
