class Solution 
{
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int a=nums[i];
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]==(a+diff))
                {
                    int b=nums[j];
                    for(int k=j+1;k<n;k++)
                    {
                        if(nums[k]==(b+diff))
                            cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
