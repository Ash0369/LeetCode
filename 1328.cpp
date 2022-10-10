class Solution 
{
public:
    string breakPalindrome(string palindrome) 
    {
        int n=palindrome.length();
        for(int i=0;i<n;i++)
        {
            
            if(palindrome[i]!='a' && !(n%2!=0 && i==(n/2)))
            {
                palindrome[i]='a';
                return palindrome;
            }
            else if(n>1 && i==n-1)
            {
                palindrome[i]='b';
                return palindrome;
            }
        }
        return "";
    }
};
