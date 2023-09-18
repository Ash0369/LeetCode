class Solution 
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<vector<int>>vec;
        for(int i=0;i<mat.size();i++)
        {
            int cnt=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {
                    cnt++;
                }
                else{
                    break;
                }
            }
            vec.push_back({cnt,i});
        }
        sort(vec.begin(),vec.end());
        vector<int>ans;
        int i=0;
        while(k--)
        {
            ans.push_back(vec[i][1]);
            i++;
        }
        return ans;
    }
};
