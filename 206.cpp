class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next_p=head;
        while(next_p!=NULL)
        {
            curr=next_p;
            next_p=curr->next;
            curr->next=prev;
            prev=curr;
        }
        return prev;
    }
};
