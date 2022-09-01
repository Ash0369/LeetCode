bool check(ListNode *head,TreeNode *root)
{
    if(head==NULL)
    {
        return true;
    }
    bool a=false;
    bool b=false;
    if(root->left && root->left->val==head->val)
    {
        a=check(head->next,root->left);
    }
    if(root->right && root->right->val==head->val)
    {
        b=check(head->next,root->right);
    }
    
    return a|b;
}
bool match(ListNode *head,TreeNode *root)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->val==head->val)
    {
        bool res=check(head->next,root);
        if(res)
        {
            return true;
        }
    }
    bool a=match(head,root->left);
    bool b=match(head,root->right);
    
    return a|b;
}
class Solution 
{
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        return match(head,root);
    }
};
