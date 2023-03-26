class Solution 
{
public:
    bool primeSubOperation(vector<int>& nums) 
    {
        set<int>st;
        for(int i=2;i<=1000;i++)
        {
            int cnt=0;
            for(int j=2;j<i;j++)
            {
                if(i%j==0)
                {
                    cnt++;
                }
            }
            if(cnt==0)
            {
                st.insert(i);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            int ele=nums[i];
            if(i!=0)
            {
                ele=nums[i]-nums[i-1];
            }
            auto it=st.lower_bound(ele);
            
            if (it != begin(st))
            {
                nums[i] -= *(--it);
            }
            
            if (i>0 && nums[i]<=nums[i - 1])
            {
                return false;
            }
            
        }
        return true;
    }
};
