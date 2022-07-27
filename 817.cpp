class Solution 
{
public:
    int numComponents(ListNode* head, vector<int>& nums) 
    {
        vector<bool>visited(10001,false);
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        bool result=false;
        int counter=0;
        int passed=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(s.find(temp->val)!=s.end())
            {
                passed++;
            }
            else
            {
                if(passed>0)
                {
                    counter++;
                    passed=0;
                }
            }
            temp=temp->next;
        }
        if(passed>0)
        {
            counter++;
        }
        return counter;
    }
};
