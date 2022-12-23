class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        string a=to_string(x);
        reverse(a.begin(),a.end());
        return to_string(x)==a;
    }
};
