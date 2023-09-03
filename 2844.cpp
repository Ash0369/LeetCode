class Solution 
{
public:
    int minimumOperations(string nums) 
    {
        int n=nums.size();
        int op=0;
        vector<vector<int>>v(4);
        int p1=-1;
        int p2=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]=='0' && p1==-1)
            {
                p1=i;
            }
            else if(nums[i]=='0' && p2==-1)
            {
                p2=i;
                break;
            }
        }
        int ans1=n-p1-1+(p1-p2-1);
        if(p1==-1 || p2==-1)
        {
            ans1=150;
        }
        p1=-1;
        p2=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]=='0' && p1==-1)
            {
                p1=i;
            }
            if(nums[i]=='5' && p1!=-1)
            {
                p2=i;
                break;
            }
        }
         int ans2=n-p1-1+(p1-p2-1);
        if(p1==-1 || p2==-1)
        {
            ans2=150;
        }
         p1=-1;
        p2=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]=='5' && p1==-1)
            {
                p1=i;
            }
            if(nums[i]=='2' && p1!=-1)
            {
                p2=i;
                break;
            }
        }
         int ans3=n-p1-1+(p1-p2-1);
        if(p1==-1 || p2==-1)
        {
            ans3=150;
        }
        p1=-1;
        p2=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]=='5' && p1==-1)
            {
                p1=i;
            }
            if(nums[i]=='7' && p1!=-1)
            {
                p2=i;
                break;
            }
        }
        
        int ans4=n-p1-1+(p1-p2-1);
        if(p1==-1 || p2==-1)
        {
            ans4=150;
        }
        int op1=n;
        for(auto x:nums)
        {
            if(x=='0')
            {
                op1=n-1;
                break;
            }
        }
        return min(op1,min(ans1,min(ans2,min(ans3,ans4))));
    }
};
