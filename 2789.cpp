class Solution 
{
public:
    long long maxArrayValue(vector<int>&nums) 
    {
        #define ll long long
        vector<ll int>vec;
        for(auto x:nums)
        {
            vec.push_back(x);
        }
        int n=vec.size();
        ll int ans=vec[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(vec[i+1]>=vec[i])
            {
                vec[i]=vec[i+1]+vec[i];
                
            }
            ans=max(ans,1LL*vec[i]);
        }
        return ans;
    }
};
