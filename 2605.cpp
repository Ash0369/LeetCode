class Solution 
{
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums2.begin(),nums2.end());
        set<int>st(nums1.begin(),nums1.end());
        for(auto x:nums2)
        {
            if(st.find(x)!=st.end())
            {
                return x;
            }
        }
        int a=(*st.begin());
        int b=nums2[0];
        return (10*min(a,b))+max(a,b);
    }
};
