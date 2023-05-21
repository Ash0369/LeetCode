class Solution 
{
public:
    string makeSmallestPalindrome(string s) 
    {
        int n=s.size();
        int j=n-1;
        int i=0;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
                continue;
            }
            else
            {
                s[i]=min(s[i],s[j]);
                s[j]=s[i];
            }
            i++;
            j--;
            
        }
        return s;
    }
};
