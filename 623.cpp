TreeNode* add(TreeNode *root,int val,int depth,int cur_depth)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(cur_depth==depth-1)
    {
        TreeNode *l=new TreeNode(val);
        TreeNode *r=new TreeNode(val);
        
        l->left=root->left;
        r->right=root->right;
        
        root->left=l;
        root->right=r;
        
        return root;
    }
    
    root->left=add(root->left,val,depth,cur_depth+1);
    root->right=add(root->right,val,depth,cur_depth+1);
    
    return root;
}
class Solution 
{
public:
    TreeNode* addOneRow(TreeNode* &root, int val, int depth) 
    {
        if(depth==1)
        {
            TreeNode *temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        return add(root,val,depth,1);
    }
};
