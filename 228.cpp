class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return {};
        }
        vector<string>ans;
        sort(nums.begin(),nums.end());
        int start=nums[0];
        for(int i=1;i<=nums.size();i++)
        {
            if(i==nums.size() || nums[i]>(nums[i-1]+1))
            {
                int end=nums[i-1];
                if(start==end)
                {
                     string temp;
                     temp=temp+to_string(start);
                     ans.push_back(temp);
                     if(i!=nums.size())
                     {
                         start=nums[i];
                     }
                    continue;
                }
                string temp;
                temp=temp+to_string(start);
                temp+="->";
                temp+=to_string(end);
                ans.push_back(temp);
                if(i!=nums.size())
                {
                    start=nums[i];
                }
            }
        }
        return ans;
        
    }
};
