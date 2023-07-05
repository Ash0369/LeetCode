class Solution 
{
public:
    int sumImbalanceNumbers(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            multiset<int>st;
            st.insert(nums[i]);
            int imbalance=0;
            for(int j=i+1;j<n;j++)
            {
                //Find element just greater and smaller then the curent number
                auto ele=st.lower_bound(nums[j]);
                int right=-1;
                int left=-1;
                if(ele!=st.end())
                {
                    right=*ele;
                }
                
                if(ele!=st.begin())
                {
                    --ele;
                    left=*ele;
                }
                if(left==-1)
                {
                    if(right-nums[j]>1)
                    {
                        imbalance++;
                    }
                }
                if(right==-1)
                {
                    if(nums[j]-left>1)
                    {
                        imbalance++;
                    }
                }
                
                if(right!=-1 && left!=-1 && right-left>1)
                {
                    if(right-nums[j]>1)
                    {
                        imbalance++;
                    }
                    if(nums[j]-left>1)
                    {
                        imbalance++;
                    }
                    imbalance--;
                }
                ans+=imbalance;
                st.insert(nums[j]);
            }
            
        }
        return ans;
    }
};
