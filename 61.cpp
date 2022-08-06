//Method-1 : Brute Force Approach

class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        deque<int>dq;
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            dq.push_back(temp->val);
            temp=temp->next;
            count++;
        }
        ListNode* dummy_head=new ListNode(-1);
        dummy_head->next=NULL;
        int to_rem=k%count;
        while(to_rem>0 && !dq.empty())
        {
            temp=new ListNode(dq.back());
            ListNode* nxt=dummy_head->next;
            dummy_head->next=temp;
            temp->next=nxt;
            to_rem--;
            dq.pop_back();
        }
        temp=head;
        to_rem=count-(k%count)-1;
        while(to_rem>0)
        {
            temp=temp->next;
            to_rem--;
        }
        temp->next=NULL;
        temp=dummy_head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
        return dummy_head->next;
    }
    
};

//Method-2 : Optimized way

class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            length++;
        }
        int rem=k%length;
        if(rem==0)
        {
            return head;
        }
        int to_traverse=length-rem-1;
        temp=head;
        while(to_traverse>0)
        {
            temp=temp->next;
            to_traverse=to_traverse-1;
        }
        ListNode* rev_head=temp->next;
        temp->next=NULL;

        temp=rev_head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
        return rev_head;
    }  
};
