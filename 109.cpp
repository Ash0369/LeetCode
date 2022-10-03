TreeNode *make(ListNode* head)
{
    if(head==NULL)
        return NULL;
    ListNode *slow=head;
    ListNode *fast=head;
    ListNode *dummy=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        dummy=slow;
        slow=slow->next;
    }
    TreeNode *node =new TreeNode(slow->val);
    ListNode *ptr=slow->next;
    
    if(dummy!=NULL)
    {
         dummy->next=NULL;
         node->left=make(head);
         node->right=make(ptr);
    }
    
    return node;
}
class Solution 
{
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        return make(head);
    }
};
