//Time Complexity O(2n) and Space Complexity O(1)

class Solution 
{
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        ListNode* prev=NULL;
        int middle=length/2;
        temp=head;
        while(middle>0)
        {
            prev=temp;
            temp=temp->next;
            middle--;
        }
        if(prev==NULL)
        {
            return NULL;
        }
        ListNode*to_del=temp;
        prev->next=temp->next;
        delete(to_del);

        return head;
    }
};
