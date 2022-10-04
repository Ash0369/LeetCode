//Method-1:


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


//Method-2 : 

int count(ListNode *head)
{
    if(head==NULL)
        return 0;
    return 1+count(head->next);
}
TreeNode *make(ListNode* &head,int n)
{
    if(n==0)
        return NULL;
    
    TreeNode *lft=make(head,n/2);
    TreeNode *root=new TreeNode(head->val);
    head=head->next;
    root->left=lft;
    
    root->right=make(head,n-(n/2)-1);
    
    return root;
}
class Solution 
{
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        int n=count(head);
        return make(head,n);
    }
};
