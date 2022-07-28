//Method-1 : Time Complexity : O(nlog(n))  , Space Complexity : O(n)

class Solution 
{
public:
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL)
        {
            return head;
        }
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        ListNode* temp=head;
        while(temp!=NULL)
        {
            pq.push(make_pair(temp->val,temp));
            temp=temp->next;
        }
        ListNode* new_head=new ListNode(INT_MAX);
        ListNode* ptr=new_head;

        cout<<pq.size()<<endl;

        while(!pq.empty())
        {
            if(new_head->val==INT_MAX)
            {
                new_head=pq.top().second;
                ptr=new_head;
            }
            else
            {
                ptr->next=pq.top().second;
                ptr=ptr->next;
            }
            pq.pop();
        }
        ptr->next=NULL;
        return new_head;
    }
};


//Method-2 : Time Complexity : O(nlog(n))  , Space Complexity : O(1)


ListNode* merge_list(ListNode* head1,ListNode* head2)
{
    ListNode* p1=head1;
    ListNode* p2=head2;

    ListNode* head;
    if(head1->val>=head2->val)
    {
        head=head2;
        p2=p2->next;
    }
    else
    {
        head=head1;
        p1=p1->next;
    }

    ListNode* ptr=head;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->val >= p2->val)
        {
            ptr->next=p2;
            p2=p2->next;
        }
        else
        {
            ptr->next=p1;
            p1=p1->next;
        }
        ptr=ptr->next; 
    }

    while(p1!=NULL)
    {
        ptr->next=p1;
        ptr=ptr->next;
        p1=p1->next;
    }

    
    while(p2!=NULL)
    {
        ptr->next=p2;
        ptr=ptr->next;
        p2=p2->next;
    }

    return head;
}
class Solution 
{
public:
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* temp=NULL;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            temp=slow;
            slow=slow->next;
        }
        temp->next=NULL;

        //We have 2 linked list one at head =head and one at head=slow

        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);

        return merge_list(l1,l2);
    }
};
