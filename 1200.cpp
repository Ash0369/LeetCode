class Solution 
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++)
        {
            ans=min(ans,arr[i+1]-arr[i]);
        }
        vector<vector<int>>res;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1]-arr[i]==ans)
            {
                res.push_back({arr[i],arr[i+1]});
            }
        }
        return res;
    }
};
