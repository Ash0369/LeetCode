#define ll long long
class Solution 
{
public:
    long long findTheArrayConcVal(vector<int>& nums) 
    {
        ll int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            int x=nums.back();
            if(i==n-1)
            {
                ans+=nums[i];
                break;
            }
            ans+=stoi(to_string(ele)+to_string(x));
            nums.pop_back();
            n--;
            
        }
        return ans;
    }
};
