//Method-1 : Unoptimized Solution

TreeNode *construct(vector<int>&nums)
{
    if(nums.size()==0)
        return NULL;
    
    int max_value=INT_MIN;
    int index;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>max_value)
        {
            max_value=nums[i];
            index=i;
        }
    }
    vector<int>left;
    vector<int>right;
    
    for(int i=0;i<index;i++)
        left.push_back(nums[i]);
    
    for(int i=index+1;i<nums.size();i++)
        right.push_back(nums[i]);
    
    TreeNode *root=new TreeNode(max_value);
    root->left=construct(left);
    root->right=construct(right);
    return root;
}
class Solution 
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        TreeNode *root;
        return construct(nums);
    }
};

//Method-2 : Binary Search

TreeNode *construct(vector<int>&nums,int l,int r)
{
    if(l>r)
        return NULL;
    
    int max_value=INT_MIN;
    int index;
    for(int i=l;i<=r;i++)
    {
        if(nums[i]>max_value)
        {
            max_value=nums[i];
            index=i;
        }
    }  
    TreeNode *root=new TreeNode(max_value);
    root->left=construct(nums,l,index-1);
    root->right=construct(nums,index+1,r);
    return root;
}
class Solution 
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        TreeNode *root;
        return construct(nums,0,nums.size()-1);
    }
};
