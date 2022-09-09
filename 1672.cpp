class Solution 
{
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int mx=0;
        for(int i=0;i<accounts.size();i++)
        {
            int x=accumulate(accounts[i].begin(),accounts[i].end(),0);
            if(x>mx)
            {
                mx=x;
            }
        }
        return mx;
        
    }
};
