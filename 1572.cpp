class Solution 
{
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int ans=0;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            ans+=mat[i][i];
        }
        int j=n-1;
        for(int i=0;i<n;i++)
        {
            ans+=mat[i][j];
            j--;
        }
        if(n%2==0)
        {
            return ans;
        }
        ans-=mat[n/2][n/2];
        return ans;
    }
};
