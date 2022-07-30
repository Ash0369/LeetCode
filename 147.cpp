class Solution 
{
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* dummy=new ListNode(0); //head of sorted

        ListNode* temp=head;
        while(temp!=NULL)
        {
            ListNode*nxt=temp->next;
            if(dummy->next==NULL)
            {
                dummy->next=temp;
                temp->next=NULL;
            }
            else
            {
                ListNode* ptr=dummy;
                while(ptr->next!=NULL && ptr->next->val<temp->val)
                {
                    ptr=ptr->next;
                }
                if(ptr->next!=NULL)
                {
                    temp->next=ptr->next;
                    ptr->next=temp;
                }
                else
                {
                    ptr->next=temp;
                    temp->next=NULL;
                }
            }
            temp=nxt;
        }
        return dummy->next;
    }
};
