int counter=0;
void swap(int &a,int &b)
{
    int c=a;
    a=b;
    b=c;
    return;
}
void permutation(vector<int>&nums,int index)
{
    if(index==nums.size())
    {
        counter++;
        return;
    }
    for(int i=index;i<nums.size();i++)
    {
        swap(nums[index],nums[i]);
        if(nums[index]%(index+1)==0  || (index+1)%nums[index]==0)
        {
            permutation(nums,index+1);
        }
        swap(nums[index],nums[i]);
    }
}
class Solution 
{
public:
    int countArrangement(int n) 
    {
        counter=0;
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        permutation(nums,0);
        return counter;
    }
};
