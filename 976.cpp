//Method-1 : Brute Force


class Solution 
{
public:
    int largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),greater<int>());
        
        int j=0;
        while(j<nums.size())
        {
            int i=j+2;
            while(i<nums.size())
            {
                if(nums[j+1]+nums[i] > nums[j])
                    return nums[j+1]+nums[j]+nums[i];
                
                i++;
            }
            j++;
        }
        
        return 0;
    }
};
