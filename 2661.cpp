class Solution 
{
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=i;
        }
        
        int m=mat.size();
        int n=mat[0].size();
        int ans=1e6;
        for(int i=0;i<m;i++)
        {
            int mx=0;
            for(int j=0;j<n;j++)
            {
                int index=mp[mat[i][j]];
                mx=max(mx,index);
            }
            ans=min(ans,mx);
        }
        
        for(int i=0;i<n;i++)
        {
            int mx=0;
            for(int j=0;j<m;j++)
            {
                int index=mp[mat[j][i]];
                mx=max(mx,index);
            }
            ans=min(ans,mx);
        }
        return ans;
    }
};
