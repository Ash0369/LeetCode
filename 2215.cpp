class Solution 
{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int>mp1;
        map<int,int>mp2;
        for(auto x:nums1)
        {
            mp1[x]++;
        }
        for(auto x:nums2)
        {
            mp2[x]++;
        }
        vector<int>ans1;
        vector<int>ans2;
        for(auto x:mp1)
        {
            if(mp2.find(x.first)==mp2.end())
            {
                ans1.push_back(x.first);
            }
        }
        for(auto x:mp2)
        {
            if(mp1.find(x.first)==mp1.end())
            {
                ans2.push_back(x.first);
            }
        }
        return {ans1,ans2};
    }
};
