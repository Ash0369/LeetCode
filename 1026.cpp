void max_diff(TreeNode *root,int &diff,int ancestorh,int ancestorl)
{
    if(root==NULL)
    {
        return;
    }
    diff=max(diff,abs(root->val-ancestorh));
    diff=max(diff,abs(root->val-ancestorl));
    max_diff(root->left,diff,max(ancestorh,root->val),min(ancestorl,root->val));
    max_diff(root->right,diff,max(ancestorh,root->val),min(ancestorl,root->val));
    
}
class Solution 
{
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        int diff=0;
        max_diff(root,diff,root->val,root->val);
        return diff;
    }
};
