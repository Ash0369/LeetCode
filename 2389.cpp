class Solution 
{
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int>res;
        for(auto x:queries)
        {
            auto ans=lower_bound(prefix.begin(),prefix.end(),x)-prefix.begin();
            if(ans==prefix.size())
                ans--;
            
            if(prefix[ans]>x)
                ans--;
            res.push_back(ans+1);
        }
        return res;
    }
};
