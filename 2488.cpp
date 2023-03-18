//https://youtu.be/QZzDioqkRhU

class Solution 
{
public:
    int countSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int index=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==k)
            {
                index=i;
                break;
            }
        }
        
        map<int,int>right;
        int g=0;
        int s=0;
        int ans=0;
        right[0]++;
        for(int i=index+1;i<n;i++)
        {
            if(nums[i]>k)
            {
                g++;
            }
            else
            {
                s++;
            }
            
            right[g-s]++;
        }
        
        g=0;
        s=0;
        
        for(int i=index-1;i>=0;i--)
        {
            if(nums[i]>k)
            {
                g++;
            }
            else
            {
                s++;
            }
            int diff=g-s;
            ans+=right[1-diff]+right[0-diff];
        }
        return ans+right[0]+right[1];
    }
};
