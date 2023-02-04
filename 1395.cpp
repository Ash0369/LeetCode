class Solution 
{
public:
    int numTeams(vector<int>& rating) 
    {
        int n=rating.size();
        vector<int>dp1(n,0);
        vector<int>dp2(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(rating[j]>rating[i])
                {
                    dp1[i]++;
                }
                if(rating[i]>rating[j])
                {
                    dp2[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(rating[j]>rating[i])
                {
                    ans+=dp1[j];
                }
                if(rating[j]<rating[i])
                {
                    ans+=dp2[i];
                }
            }
        }
        
        return ans;
    }
};
