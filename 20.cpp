//Method-1

class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char>par;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            char x=s[i];
            if(x=='{' || x=='(' || x=='[')
            {
                par.push(x);
            }
            else
            {
                if(par.empty())
                {
                    return false;
                }
                if(x==')')
                {
                    if(par.top()!='(')
                    {
                        return false;
                    }
                    par.pop();
                }
                else if(x=='}')
                {
                    if(par.top()!='{')
                    {
                        return false;
                    }
                    par.pop();
                }
                else if(x==']')
                {
                    if(par.top()!='[')
                    {
                        return false;
                    }
                    par.pop();
                }
            }
        }
        if(par.empty())
        {
            return true;
        }
        return false;
    }
};

//Method-2

int helper(char c)
{
    if(c=='[')
    {
        return 1;
    }
    else if(c==']')
    {
        return -1;
    }
    else if(c=='{')
    {
        return 2;
    }
    else if(c=='}')
    {
        return -2;
    }
    else if(c=='(')
    {
        return 3;
    }
    else if(c==')')
    {
        return -3;
    }
    return 0;
    
}
class Solution {
public:
    bool isValid(string s) 
    {
        stack<int>par;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            int x=helper(s[i]);
            if(x>0)
            {
                par.push(x);
            }
            else
            {
                if(par.empty())
                {
                    return false;
                }
                if((x+par.top())!=0)
                {
                    return false;
                }
                par.pop();
            }
        }
        if(par.empty())
        {
            return true;
        }
        return false;
    }
};
