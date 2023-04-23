class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                cnt++;
        }
        int got=1000;
       
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            for(int j=i+1;j<n;j++)
            {
                num=__gcd(num,nums[j]);
                if(num==1)
                got=min(got,j-i-1);
            }
        }
        if(got==1000)
        {
            return -1;
        }
        return n-cnt+max(0,got);
        
    }
};
