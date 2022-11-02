//Method-1: 

class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int left=0;
        int n=nums.size();
        int cnt=0;
        
        int odd=0;
        
        for(int right=0;right<n;right++)
        {
            if(nums[right]%2!=0)
                odd++;
            
            while(odd>k)
            {
                if(nums[left]%2!=0)
                    odd--;
                left++;
            }
            int intial=left;
            if(odd==k)
            {
                cnt++;
                
            }
            while(odd==k && nums[left]%2==0)
            {
                cnt++;
                left++;
            }
            left=intial;
        
        }
        return cnt;
    }
};


//Method-2 : 


class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int left=0;
        int n=nums.size();
        int cnt=0;
        int odd=0;
        int temp=0;
        for(int right=0;right<n;right++)
        {
            if(nums[right]%2!=0)
            {
                odd++;
                if(odd>=k)
                {
                    temp=1;
                    while(nums[left]%2==0)
                    {
                        temp++;
                        left++;
                    }
                    left++;
                    cnt+=temp;
                }
            }
            else if(odd>=k)
            {
                cnt+=temp;
            }
        }
        return cnt;
    }
};
