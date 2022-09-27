class Solution 
{
public:
    vector<vector<string>>res;
    bool check(string &s)
    {
        int l=0;
        int r=s.length()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void part(string &s,int index,vector<string>&temp)
    {
        if(index==s.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=index;i<s.length();i++)
        {
            string st=s.substr(index,i-index+1);
            if(check(st))
            {
                temp.push_back(st);
                part(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<string>temp;
        part(s,0,temp);
        return res;
    }
};
