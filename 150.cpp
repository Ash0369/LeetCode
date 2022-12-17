class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<long long int>st;
        for(int i=0;i<tokens.size();i++)
        {
            string c=tokens[i];
            if(c!="+" && c!="*" && c!="-" && c!="/")
            {
                st.push(stoi(c));
            }
            else
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(c=="+")
                    st.push(a+b);
                else if(c=="*")
                    st.push(1LL*a*b);
                else if(c=="-")
                    st.push(b-a);
                else
                    st.push(b/a);
            }
        }
        return st.top();
    }
};
