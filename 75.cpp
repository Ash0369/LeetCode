//Method-1 : 

class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int ptr=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==2)
            {
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
    }
};


//Method-2 : 

class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
