//Method-1 : Iterative way

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

//Method-2 : Recursive way

ListNode* swap(ListNode* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    ListNode* temp=head->next;
    head->next=swap(head->next->next);
    temp->next=head;
    return temp;
}
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        return swap(head);
    }
};
