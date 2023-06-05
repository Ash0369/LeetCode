class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        int ele1=-1;
        int ele2=-2;
        
        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)
            {
                cnt1++;
            }
            else if(nums[i]==ele2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele1)
            {
                cnt1++;
            }
            if(nums[i]==ele2)
            {
                cnt2++;
            }
        }
        
        vector<int>ans;
        if(cnt1>(n/3))
        {
            ans.push_back(ele1);
        }
        if(cnt2>(n/3))
        {
            ans.push_back(ele2);
        }
        
        return ans;
    }
};
