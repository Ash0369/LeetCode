vector<string>result;
void generate(int open,int close,string &s,int n)
{
    if(s.length()==(2*n))
    {
        result.push_back(s);
    }
    if(open<n)
    {
        s.push_back('(');
        generate(open+1,close,s,n);
        s.pop_back();
    }
    if(close<n && close<open)
    {
        s.push_back(')');
        generate(open,close+1,s,n);
        s.pop_back();
    }
}
class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        result.clear();
        string s="(";
        generate(1,0,s,n);
        return result;
    }
};
