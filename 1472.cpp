//Method-1 : Using Stack

class BrowserHistory 
{
public:
    stack<string>st_forward;
    stack<string>st_back;
    BrowserHistory(string homepage) 
    {
        st_back.push(homepage);
    }
    
    void visit(string url) 
    {
        while(!st_forward.empty())
        {
            st_forward.pop();
        }
        st_back.push(url);
    }
    
    string back(int steps) 
    {
        string s;
        while(!st_back.empty() && steps>0)
        {
            st_forward.push(st_back.top());
            st_back.pop();
            steps--;
        }
        if(st_back.empty())
        {
            s=st_forward.top();
            st_back.push(st_forward.top());
            st_forward.pop();
        }
        else
        {
            s=st_back.top();
        }
        return s;
        
    }
    
    string forward(int steps) 
    {
        while(!st_forward.empty() && steps>0)
        {
            st_back.push(st_forward.top());
            st_forward.pop();
            steps--;
        }
        return st_back.top();
    }
};
