#define ll long long
class Solution 
{
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        ll int ans=0;
        int i=0;
        multiset<int>st;
        for(int j=0;j<nums.size();j++)
        {
            st.insert(nums[j]);
            int d=(*(--st.end()))-(*st.begin());
            while(d>2)
            {
                st.erase(st.find(nums[i]));
                i++;
                d=(*(--st.end()))-(*st.begin());
            }
            int sz=st.size();
            //cout<<j<<" "<<sz<<endl;
            ans+=sz;
        }
        return ans;
    }
};
