//Method-1 : Kepping record of the element in a set to avoid duplicate visit.

vector<vector<int>>answer;
void permute(int index,vector<int>&nums,int n)
{
    if(index==n)
    {
        answer.push_back(nums);
        return;
    }
    set<int>st;
    for(int i=index;i<n;i++)
    {
        if(st.find(nums[i])!=st.end())
        {
            continue;
        }
        st.insert(nums[i]);
        swap(nums[i],nums[index]);
        permute(index+1,nums,n);
        swap(nums[i],nums[index]);
    }
}
class Solution 
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        answer.clear();
        sort(nums.begin(),nums.end());
        permute(0,nums,nums.size());
        return answer;
    }
};
