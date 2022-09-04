TreeNode *helper(vector<int>& preorder, vector<int>& inorder,int preorder_start,int preorder_end,int inorder_start,int inorder_end)
{
    if(inorder_start>inorder_end)
    {
        return NULL;
    }
    int rootval=preorder[preorder_start];
    int rootindex=-1;
    for(int i=inorder_start;i<=inorder_end;i++)
    {
       if(rootval==inorder[i])
       {
           rootindex=i;
           break;
       }
    }
    TreeNode *root=new TreeNode(rootval);
    
    int preorder_end_left=preorder_start  +rootindex-inorder_start;
    int pre_order_start_right=preorder_end_left+1;
    root->left=helper(preorder,inorder,preorder_start+1,preorder_end,inorder_start,rootindex-1);
    root->right=helper(preorder,inorder,pre_order_start_right,preorder_end,rootindex+1,inorder_end);
    return root;
    
}
class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preorder_start=0;
        int preorder_end=preorder.size()-1;
        int inorder_start=0;
        int inorder_end=inorder.size()-1;
        
        return helper(preorder,inorder,preorder_start,preorder_end,inorder_start,inorder_end);
    }
};
