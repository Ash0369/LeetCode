char rev(char c)
{
    if(c=='z') return 'a';
    return (++c);
}
class Solution 
{
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        int j=n1-1;
        bool res=true;
        for(int i=n2-1;i>=0;i--)
        {
            char c=str2[i];
            while(j>=0 && str1[j]!=c && rev(str1[j])!=c)
            {
                j--;
            }
            if(j<0) return false;
            
            j--;
        }
        return true;
    }
};
