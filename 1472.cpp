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

//Method-2 : Using Linked List

struct List_Node 
  {
      string val;
      List_Node *next;
      List_Node *prev;
      List_Node() : val(NULL), next(nullptr) {}
      List_Node(string x) : val(x), next(nullptr),prev(nullptr) {}
      List_Node(string x, List_Node *next,List_Node* prev) : val(x), next(next),prev(prev) {}
  };
class BrowserHistory 
{
public:
    List_Node* curr;
    BrowserHistory(string homepage) 
    {
        List_Node* head=new List_Node(homepage);
        head->next=NULL;
        head->prev=NULL;
        curr=head;
    }
    
    void visit(string url) 
    {
        List_Node* temp=new List_Node(url);
        curr->next=temp;
        temp->prev=curr;
        curr=temp;
    }
    
    string back(int steps) 
    {
        while(curr->prev!=NULL && steps>0)
        {
            curr=curr->prev;
            steps--;
        }
        return curr->val;
        
    }
    
    string forward(int steps) 
    {
        while(curr->next!=NULL && steps>0)
        {
            curr=curr->next;
            steps--;
        }
        return curr->val;
    }
};
