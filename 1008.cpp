TreeNode* bst(vector<int>preorder,int start,int &i)
{
    //We have to take i by adress.
    if(i==preorder.size())
    {
        return NULL;
    }
    if(preorder[i]>start)
    {
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[i]);
    i++;
    root->left=bst(preorder,root->val,i);
    root->right=bst(preorder,start,i);
    return root;
    
}
class Solution 
{
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int i=0;
        return bst(preorder,INT_MAX,i);
        
    }
};
