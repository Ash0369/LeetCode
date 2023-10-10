
class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
        int n=nums.size();
        map<int,int>mp;
        vector<int>vec;
        for(auto x:nums)
        {
            mp[x]++;
        }
        int stock=0;
        
        for(auto x:mp)
        {
            vec.push_back(x.first);
            stock+=x.second-1;
        }
        
        int sz=vec.size();
        int left=0;
        int ans=n-1;
        sort(vec.begin(),vec.end());
        for(int right=0;right<sz;right++)
        {
            while(vec[right]>(vec[left]+n-1))
            {
                left++;
            }
            if(vec[right]-vec[left]==n-1 || stock>0)
            {
                ans=min(ans,stock+left+sz-right-1);
            }
            else if(right-left!=sz-1)
            {
                ans=min(ans,stock+left+sz-right-1);
            }
        }
        return ans;
    }
};
