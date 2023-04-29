class Solution 
{
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n=A.size();
        vector<int>ans(n,0);
        vector<int>dpa(n+1,0);
        vector<int>dpb(n+1,0);
        for(int i=0;i<n;i++)
        {
            dpa[A[i]]=1;
            dpb[B[i]]=1;
            for(int j=0;j<=n;j++)
            {
                if(dpa[j]==1 && dpb[j]==1)
                {
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};
