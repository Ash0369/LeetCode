//Method-1 : O(n) Time and Space Complexity , Using Dequeue

class Solution 
{
public:
    void reorderList(ListNode* head) 
    {
        deque<ListNode*>qu;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            qu.push_back(temp);
            temp=temp->next;
        }
        while(!qu.empty())
        {
            if(qu.size()==1)
            {
                qu.front()->next=NULL;
                qu.pop_front();
            }
            else
            {
                qu.front()->next=qu.back();
                qu.pop_front();
                if(qu.size()==1)
                {
                    qu.back()->next=NULL;
                }
                else
                {
                    qu.back()->next=qu.front();
                    qu.pop_back();
                }
            }
        }
    }
};

//Method-2 : O(n) Time and Space Complexity , using Stack

class Solution 
{
public:
    void reorderList(ListNode* head) 
    {
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }

        int k=n/2;
        temp=head;
        while(k>0)
        {
            temp=temp->next;
            k--;
        }
        if(n%2!=0)
        {
            temp=temp->next;
        }
        stack<ListNode*>st;
        while(temp!=NULL)
        {
            st.push(temp);
            temp=temp->next;
        }
        temp=head;
        while(!st.empty())
        {
            ListNode* nxt=temp->next;
            temp->next=st.top();
            st.top()->next=nxt;
            st.pop();
            temp=nxt;
        }
        temp->next=NULL;
    }
};
