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
