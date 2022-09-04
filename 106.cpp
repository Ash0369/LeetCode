inorder_end,int postorder_start,int postorder_end)
{
    if(inorder_start>inorder_end  || postorder_start>postorder_end)
    {
        return NULL;
    }
    int root_val=postorder[postorder_end];
    TreeNode *root =new TreeNode(root_val);
    int index=-1;
    for(int i=0;i<inorder.size();i++)
    {
        if(inorder[i]==root_val)
        {
            index=i;
            break;
        }
    }
    int left_postorder_end=postorder_start + index-inorder_start-1;
    int right_postorder_start=left_postorder_end+1;
    
    root->left=helper(inorder,postorder,inorder_start,index-1,postorder_start,left_postorder_end);
    root->right=helper(inorder,postorder,index+1,inorder_end,right_postorder_start,postorder_end-1);
    
    return root;
}
class Solution 
{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
