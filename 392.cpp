class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int i=0;
        int j=0;
        int m=s.size();
        int n=t.size();
        
        while(i<m)
        {
            while(j<n && s[i]!=t[j])
            {
                j++;
            }
            if(j==n)
            {
                return false;
            }
            j++;
            i++;
        }
        return true;
    }
};
