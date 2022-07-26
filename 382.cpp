//Method-1 : Space Complexity O(n)

class Solution 
{
public:
    ListNode* it;
    vector<int>result;
    Solution(ListNode* head) 
    {
        it=head;
        while(it!=NULL)
        {
            result.push_back(it->val);
            it=it->next;
        }
    }
    
    int getRandom() 
    {
        int n=result.size();
        int random_number=(rand()%n);
        return result[random_number];
    }
};

//Method-2 : Space Complexity O(1)

class Solution 
{
public:
    int n=0;
    ListNode* per_head;
    Solution(ListNode* head) 
    {
        per_head=head;
        while(head!=NULL)
        {
            n++;
            head=head->next;
        }
    }
    
    int getRandom() 
    {
        int random_number=rand()%n;
        ListNode* temp=per_head;
        while(random_number>0)
        {
            temp=temp->next;
            random_number--;
        }
        return temp->val;
    }
};
