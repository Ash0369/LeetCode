class Solution 
{
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int count=0;
        for(auto x:mp)
        {
            if(x.second>1)
            {
                int n=x.second;
                count=count+(n*(n-1)/2);
            }
            
        }
        return count;
    }
};
