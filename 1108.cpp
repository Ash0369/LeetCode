class Solution 
{
public:
    string defangIPaddr(string address) 
    {
        string ans="";
        for(auto x:address)
        {
            if(x!='.')
            {
                ans.push_back(x);
            }
            else
            {
                ans=ans+"[.]";
            }
        }
        return ans;
    }
};
