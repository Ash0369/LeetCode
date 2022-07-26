void swap(ListNode*a,ListNode*b)
{
    int c=a->val;
    a->val=b->val;
    b->val=c;
}
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                swap(temp,temp->next);
                temp=temp->next->next;
            }
            else
            {
                temp=temp->next;
            }
            
        }
        return head;
    }
};
