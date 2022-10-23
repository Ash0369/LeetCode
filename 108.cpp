TreeNode *make(vector<int>&nums,int low,int high)
{
    if(low>high)
        return NULL;
    int mid=(low+high)>>1;
    TreeNode *temp=new TreeNode(nums[mid]);
    temp->left=make(nums,low,mid-1);
    temp->right=make(nums,mid+1,high);
    return temp;
}
class Solution 
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
       int high=nums.size()-1; 
       return make(nums,0,high);
    }
};
