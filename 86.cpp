//Method-1 : Time Complexity O(n) , Sapce Complexity O(n)+O(n)

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
