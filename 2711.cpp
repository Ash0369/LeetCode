class Solution 
{
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                set<int>st;
                for(int k=0;k<min(i,j);k++)
                {
                    st.insert(grid[i-k-1][j-k-1]);
                }
                int ans1=st.size();
                st.clear();
                for(int k=0;k<min(m,n)-1;k++)
                {
                    if(i+k+1==m || j+k+1==n)
                    {
                        break;
                    }
                    st.insert(grid[i+k+1][j+k+1]);
                }
                int ans2=st.size();
                ans[i][j]=abs(ans1-ans2);
            }
        }
        return ans;
    }
};
