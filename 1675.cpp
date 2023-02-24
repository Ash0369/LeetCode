class Solution 
{
public:
    int minimumDeviation(vector<int>& nums) 
    {
        
        priority_queue<int>pq;
        int n=nums.size();
        int ans;
        sort(nums.begin(),nums.end());
        ans=nums[n-1]-nums[0];
        int mn=1e9;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2!=0)
            {
                nums[i]*=2;
            }
            mn=min(mn,nums[i]);
            pq.push(nums[i]);
        }
        while(!pq.empty())
        {
            int ele=pq.top();
            pq.pop();
            
            ans=min(ans,ele-mn);
            if(ele%2==0)
            {
                mn=min(mn,ele/2);
                pq.push(ele/2);
            }
            else
            {
                break;
            }
        }
        return ans;
        
    }
};
