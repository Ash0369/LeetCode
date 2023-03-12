#define ll long long
class Solution 
{
public:
    int maxScore(vector<int>& nums) 
    {
        int n=nums.size();
        priority_queue<int>neg;
        long long int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=0)
            {
                neg.push(nums[i]);
            }
            else
            {
                sum=sum+nums[i];
                cnt++;
            }
        }
        while(!neg.empty())
        {
           
            sum=sum+neg.top();
            neg.pop();
            if(sum>0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
