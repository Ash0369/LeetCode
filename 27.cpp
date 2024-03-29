//Method-1 : 

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n=nums.size();
        int right=n-1;
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==val)
            {
                while(nums[right]==val && right>i)
                    right--;
                swap(nums[i],nums[right]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=val)
                k++;
            else
                break;
        }
        return k;
    }
};

//Method-2 : 

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());        
        return nums.size();
    }
};
