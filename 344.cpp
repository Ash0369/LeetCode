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

//Method-3 : Using 2 Pointer


void swap(char &a,char &b)
{
    char c=a;
    a=b;
    b=c;
}
class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        int ptr1=0;
        int ptr2=s.size()-1;
        while(ptr2>ptr1)
        {
            swap(s[ptr1],s[ptr2]);
            ptr1++;
            ptr2--;
        }
    }
};
