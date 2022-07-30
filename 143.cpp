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
