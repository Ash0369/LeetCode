//Method-1 : Using Inbuilt reverse Time Complexity O(n)

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        reverse(s.begin(),s.end());
    }
};

//Method-2 : Using stack

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            st.push(s[i]);
        }
        for(int i=0;i<s.size();i++)
        {
            s[i]=st.top();
            st.pop();
        }
    }
};
