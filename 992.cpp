//Method-1 : 

https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235235/C%2B%2BJava-with-picture-prefixed-sliding-window


class Solution 
{
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int left=0;
        map<int,int>mp;
        int cnt=0;
        int unique=0;
        int temp=0;
        int prefix=0;
        for(int right=0;right<n;right++)
        {
            mp[nums[right]]++;
            if(mp[nums[right]]==1)
            {
                unique++;   
            }
            while(unique>k)
            {
                if(mp[nums[left]]==1)
                    unique--;
                mp[nums[left]]--;
                left++;
                prefix=0;
            }
            while(mp[nums[left]]>1)
            {
                mp[nums[left]]--;
                prefix++;
                left++;
            }
           
           
            if(unique==k)
                 cnt+=prefix+1;   
        }
        return cnt;
    }
};
