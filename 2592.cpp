//Method-1 : 

class Solution 
{
public:
    int maximizeGreatness(vector<int>& nums) 
    {
        multiset<int>st(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int ans=0;
        for(auto x:nums)
        {
            auto ind=st.upper_bound(x);
            if(ind==st.end())
            {
                break;
            }
            ans++;
            st.erase(ind);
        }
        return ans;
    }
};

//Method-2 : 

class Solution 
{
public:
    int maximizeGreatness(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        int index=0;
        for(auto x:nums)
        {
            if(x>nums[index])
            {
                index++;
                ans++;
            }
        }
        return ans;
    }
};
