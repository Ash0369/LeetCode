void insertion_at_tail(ListNode* &head,int data)
{
    ListNode* n=new ListNode(data);
    if(head==NULL)
    {
        head=n;
    }
    else
    {
        ListNode* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* p1=list1;
        ListNode* p2=list2;
        ListNode* head=NULL;
        while(p1!=NULL || p2!=NULL)
        {
            if(p1!=NULL && p2!=NULL)
            {
                if(p1->val>=p2->val)
                {
                    insertion_at_tail(head,p2->val);
                    p2=p2->next;
                }
                else
                {
                    insertion_at_tail(head,p1->val);
                    p1=p1->next;
                }
            }
            else if(p1!=NULL)
            {
               insertion_at_tail(head,p1->val);
               p1=p1->next;
            }
            else if(p2!=NULL)
            {
               insertion_at_tail(head,p2->val);
               p2=p2->next;
            }
        }
        return head;

    }
};
