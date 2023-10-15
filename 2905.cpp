class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id,int vd) {
        int n=nums.size();
        vector<int>smax(n,0);
        
        vector<int>smin(n,0);
        smax[n-1]=n-1;
        smin[n-1]=n-1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(nums[smax[i+1]]<nums[i])
            {
                smax[i]=i;
            }
            else{
                smax[i]=smax[i+1];
            }
            if(nums[smin[i+1]]>nums[i])
            {
                smin[i]=i;
            }
            else{
                smin[i]=smin[i+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            if(i+id<n)
            {
                if(abs(curr-nums[smax[i+id]])>=vd)
                {
                    return {i,smax[i+id]};
                }
                if(abs(curr-nums[smin[i+id]])>=vd)
                {
                    return {i,smin[i+id]};
                }
            }
        }
        return {-1,-1};
    }
};
