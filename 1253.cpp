class Solution 
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
    {
        int n=2;
        int m=colsum.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(colsum[i]==2)
            {
                upper--;
                lower--;
                ans[0][i]=1;
                ans[1][i]=1;
            }
            else if(colsum[i]==1)
            {
                if(upper>=lower)
                {
                    ans[0][i]=1;
                    upper--;
                }
                else
                {
                    ans[1][i]=1;
                    lower--;
                }
            }
        }
        if(upper!=0 || lower!=0)
        {
            return {};
        }
        return ans;
    }
};
