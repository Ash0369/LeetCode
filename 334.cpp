//Method-1 : Recursive - High Time Complexity so Large Test Case will not pass


bool search(vector<int>&nums,int index,int prev,int count)
{
    if(count==3)
        return true;
    if(index==nums.size())
        return false;
    
    bool b=search(nums,index+1,prev,count);
    bool a=false;
    if(nums[index]>prev)
        a=search(nums,index+1,nums[index],count+1);
    
    return a|b;
   
}
class Solution 
{
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        return search(nums,0,INT_MIN,0);
    }
};
