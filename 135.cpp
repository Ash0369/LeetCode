class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        int tot=0;
        int n=ratings.size();
        vector<int>candy(n,1);
        for(int i=0;i<n;i++)
        {
            int k=1;
            while(i<n-1 && ratings[i+1]>ratings[i])
            {
                candy[i+1]=1+candy[i];
                i++;
            }
            if(k!=1)
            {
                i--;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            int k=1;
            while(i>0 && ratings[i-1]>ratings[i])
            {
                if(candy[i-1]<=candy[i])
                {
                    candy[i-1]=1+candy[i];
                }
                i--;
            }
            if(k!=1)
            {
                i++;
            }
        }
        int ans=accumulate(candy.begin(),candy.end(),0);
        return ans;
    }
};
