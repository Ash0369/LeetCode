#define ll long long
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n=(nums.size())/2;
        sort(nums.begin(),nums.end());
        ll int count=0;
        ll int ele=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele)
            {
                count++;
                
            }
            else
            {
                ele=nums[i];
                count=1;
            }

            if(count>=(n+1))
            {
                return ele;
            }
        }
        return ele;

    }
};
