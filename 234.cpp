//Method-1 : using Stack , O(n) Time and Space Complexity

class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        stack<int>st;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(!st.empty())
        {
            if(temp->val!=st.top())
            {
                return false;
            }
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};

//Method-2 : Using deque

class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        deque<int>dq;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            dq.push_back(temp->val);
            temp=temp->next;
        }
        while(!dq.empty() && dq.size()!=1)
        {
            if(dq.front()!=dq.back())
            {
                return false;
            }
            dq.pop_back();
            dq.pop_front();
        }
        return true;
    }
};

//Method-3 : Using Recursion

ListNode* temp;
bool checker(ListNode* head)
{
    if(head==NULL)
    {
        return true;
    }
    bool res=checker(head->next);
    if(head->val!=temp->val)
    {
        return false;
    }
    temp=temp->next;
    return res;
}
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        temp=head;
        return checker(head);
    }
};
