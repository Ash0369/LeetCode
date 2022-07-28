//Method-1 : Using Queue --> Time Complexity O(n) , Sapce Complexity O(n)+O(n)

class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        queue<ListNode*>smaller;
        queue<ListNode*>greater;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(temp->val>=x)
            {
                greater.push(temp);
            }
            else
            {
                smaller.push(temp);
            }
            temp=temp->next;
        }
        if(smaller.empty())
        {
            return head;
        }
        ListNode* new_head=smaller.front();
        smaller.pop();
        ListNode*ptr=new_head;
        while(!smaller.empty())
        {
            ptr->next=smaller.front();
            ptr=ptr->next;
            smaller.pop();
        }

        while(!greater.empty())
        {
            ptr->next=greater.front();
            ptr=ptr->next;
            greater.pop();
        }
        ptr->next=NULL;

        return new_head;

    }
};

//Method-2 : Time Complexity O(n) and Space Complexity O(1)

class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        if(head== NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* grt_head=NULL;
        ListNode* small_head=NULL;
        ListNode* grt_ptr=grt_head;
        while(curr!=NULL)
        {
            if(curr->val>=x)
            {
                if(grt_head==NULL)
                {
                    grt_head=curr;
                    grt_ptr=grt_head;
                }
                else
                {
                    grt_ptr->next=curr;
                    grt_ptr=grt_ptr->next;
                }
                ListNode* temp=curr;
                if(prev!=NULL)
                {
                    prev->next=curr->next;
                }
                curr=curr->next;
                temp->next=NULL;
            }
            else
            {
                if(small_head==NULL)
                {
                    small_head=curr;
                }
                prev=curr;
                curr=curr->next;
            }
            
        }
        if(prev==NULL)
        {
            return grt_head;
        }
        prev->next=grt_head;
        return small_head;

    }
};
