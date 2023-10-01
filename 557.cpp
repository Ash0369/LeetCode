class Solution 
{
public:
    string reverseWords(string s) 
    {
        string ans="";
        string temp="";
        for(auto x:s)
        {
            if(x==' ')
            {
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans.push_back(' ');
                temp="";
            }
            else
            {
                temp.push_back(x);
            }
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};
