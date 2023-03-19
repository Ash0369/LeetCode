//Method-1 : 

int ways(int index,vector<int>&nums,vector<int>&taken,int k)
{
    if(index==nums.size())
    {
        return 1;
    }
    int ele=nums[index];
    int ans=ways(index+1,nums,taken,k);//Not pick
    bool res=true;
    for(auto x:taken)
    {
        if(abs(x-ele)==k)
        {
            res=false;
            break;
        }
    }
    if(res)
    {
        taken.push_back(ele);
        int ans2=ways(index+1,nums,taken,k);
        taken.pop_back();
        return ans+ans2;
    }
    return ans;
}
class Solution 
{
public:
    int beautifulSubsets(vector<int>& nums, int k) 
    {
        vector<int>taken;
        return ways(0,nums,taken,k)-1;
    }
};

//Method-2 : 

