class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* odd_head=head;
        ListNode*even_head=head->next;

        ListNode* oddt=odd_head;
        ListNode* event=even_head;

        int k=1;
        head=head->next->next;
        while(head!=NULL)
        {
            if(k%2!=0)
            {
                oddt->next=head;
                oddt=oddt->next;   
            }
            else
            {
                event->next=head;
                event=event->next;
            }
            head=head->next;
            k++;
        }
        event->next=NULL;
        oddt->next=even_head;
        return odd_head;
    }
};
