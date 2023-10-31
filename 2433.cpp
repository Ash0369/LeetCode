class Solution 
{
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int n=pref.size();
        vector<int>vec(n);
        vec[0]=pref[0];
        for(int i=1;i<n;i++)
        {
            vec[i]=pref[i-1]^pref[i];
        }
        return vec;
    }
};
