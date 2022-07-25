//Method-1 : Creating a New Linked List

class Solution 
{
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* new_head=NULL;
        ListNode* ptr=new_head;
        head=head->next;
        long long int sum=0;
        while(head!=NULL)
        {
            if(head->val!=0)
            {
                sum=sum+head->val;
            }
            else
            {
                if(new_head==NULL)
                {
                    ListNode* temp=new ListNode(sum);
                    new_head=temp;
                    ptr=new_head;
                }
                else
                {
                    ListNode* temp=new ListNode(sum);
                    ptr->next=temp;
                    ptr=ptr->next;
                }
                sum=0;
            }
            head=head->next;
        }
        return new_head;
    }
};

//By 2 Pointer approach

class Solution 
{
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* curr=head->next;
        ListNode* prev=NULL;
        int sum=0;
        while(curr!=NULL)
        {
            sum=sum+curr->val;
            if(curr->val==0)
            {
                curr->val=sum;
                if(prev==NULL)
                {
                    head=curr;
                }
                else
                {
                    prev->next=curr;
                }
                prev=curr;
                sum=0;
            }
            curr=curr->next;
        }
        return head;
    }
};
