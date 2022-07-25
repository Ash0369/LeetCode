//Method-1 : Iterative Approach

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

//Recursive Approach


ListNode* reverse(ListNode* head)
{
    if(head->next!=NULL)
    {
        ListNode* temp;
        temp=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    
    return head;
    
}
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        return reverse(head);
    }
};
