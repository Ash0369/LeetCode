class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n=s.size();
        string temp="";
        for(int i=0;i<n-1;i++)
        {
            temp.push_back(s[i]);
            if(n%(i+1)==0)
            {
                int k=n/(i+1);
                string t="";
                while(k--) t+=temp;
                if(s==t)return true;
            }
        }
        return false;
    }
};
