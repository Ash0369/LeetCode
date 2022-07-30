//Method-1 : Using Inbuilt reverse Time Complexity O(n)

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        reverse(s.begin(),s.end());
    }
};
