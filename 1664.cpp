class Solution 
{
public:
    int waysToMakeFair(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>odd(n,0);
        vector<int>even(n,0);
        even[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(i%2==0)
            {
                even[i]=even[i-1]+nums[i];
                odd[i]=odd[i-1];
            }
            else if(i%2!=0)
            {
                odd[i]=odd[i-1]+nums[i];
                even[i]=even[i-1];
            }
        }
        int ways=0;
        for(int i=0;i<n;i++)
        {
            //If we delete this index all index aftr this change
            int oddaftr=odd[n-1]-odd[i];
            int evenaftr=even[n-1]-even[i];
            int oddbfr=(i>0) ? odd[i-1] : 0;
            int evenbfr= (i>0) ? even[i-1] : 0;
            if(oddbfr+evenaftr==evenbfr+oddaftr)
            {
                ways++;
            }
        }
        return ways;
    }
};
