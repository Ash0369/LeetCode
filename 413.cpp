//Method-1 : 

class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            int d=nums[i+1]-nums[i];
            for(int j=i+2;j<n;j++)
            {
                if((nums[j]-nums[j-1])==d)
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};


//Method-2 : 

class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        if(n<3)
        {
            return 0;
        }
        int cnt=0;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i+1]-nums[i]==nums[i]-nums[i-1])
            {
                cnt++;
                ans+=cnt;
            }
            else
            {
                cnt=0;
            }
        }
        return ans;
    }
};
