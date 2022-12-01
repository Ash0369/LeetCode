bool check(char a)
{
    a=tolower(a);
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
        return true;
    return false;
}
class Solution 
{
public:
    bool halvesAreAlike(string s) 
    {
        int cnt=0;
        for(int i=0;i<s.size()/2;i++)
        {
            if(check(s[i]))
                cnt++;
        }
        for(int i=s.size()/2;i<s.size();i++)
        {
            if(check(s[i]))
                cnt--;
        }
        return cnt==0;
    }
};
