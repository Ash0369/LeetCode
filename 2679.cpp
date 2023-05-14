class Solution 
{
public:
    int matrixSum(vector<vector<int>>& nums) 
    {
        int sz=nums[0].size();
        int n=nums.size();
        vector<vector<int>>vec(n+1);
        
        for(int i=0;i<n;i++)
        {
            auto x=nums[i];
            sort(x.begin(),x.end(),greater<int>());
            vec[i]=x;
        }
        
        int ans=0;
        
        for(int i=0;i<sz;i++)
        {
            int temp=0;
            for(int j=0;j<n;j++)
            {
                temp=max(temp,vec[j][i]);
            }
            ans+=temp;
        }
        return ans;
    }
};
