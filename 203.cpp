class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* temp=head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                prev->next=temp->next;
            }
            else
            {
                prev=temp;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};
