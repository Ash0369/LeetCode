//Method-1

ListNode* reverse(ListNode* a)
{
    ListNode* prev=NULL;
    ListNode* curr=a;
    ListNode* nxt=a->next;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        int k=1;
        ListNode* temp=head;
        ListNode* prev=NULL;      
        while(temp!=NULL)
        {
            if(k==left)
            {
                ListNode* curr=temp;
                while(k!=right)
                {
                    temp=temp->next;
                    k++;
                }
                ListNode* nxt=temp->next;
                temp->next=NULL;
                ListNode* new_head=reverse(curr);
                if(prev!=NULL)
                {
                    prev->next=new_head;
                }
                curr=new_head;
                while(curr->next!=NULL)
                {
                    curr=curr->next;
                }
                curr->next=nxt;
                if(left==1)
                {
                    return new_head;
                }
                break;
            }
            k++;
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};

//Method-2 

class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head==NULL)
        {
            return head;
        }
        if(left==right)
        {
            return head;
        }

        ListNode* prev=NULL;
        ListNode dummy(NULL); //If our prev =NULL then our code will not work so we use dummy node so that our previous is never NULL
        prev=&dummy;
        dummy.next=head;
        int k=1;
        while(k!=left)
        {
            prev=prev->next;
            k++;
        }
        ListNode* tail;
        k=right-left;
        tail=prev->next;
        while(k>0)
        {
            k--;
            ListNode* temp;
            temp=prev->next;
            prev->next=tail->next;
            tail->next=tail->next->next;
            prev->next->next=temp;
        }
        return dummy.next;
    }
};
