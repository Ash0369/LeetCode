//Method-1 : Pre Calculating Size ,Time Complexity O(2n) and Space Complexity O(1)

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

//Method-2 : 2 Pointers

class Solution 
{
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if(fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
        }

        ListNode* todel=slow;
        prev->next=slow->next;
        delete(todel);

        return head;
    }
};
