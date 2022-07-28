void swap(ListNode* l1,ListNode* l2)
{
    int c=l1->val;
    l1->val=l2->val;
    l2->val=c;
}
class Solution 
{
public:
    void deleteNode(ListNode* node) 
    {
        ListNode* prev=NULL;
        while(node->next!=NULL)
        {
            prev=node;
            swap(node,node->next);
            node=node->next;
        }
        prev->next=NULL;
        
    }
};
