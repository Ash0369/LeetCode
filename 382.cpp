//Space Complexity O(n)

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
