int check(char a)
{
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
    {
        return 1;
    }
    return 0;
}
class Solution 
{
public:
    int maxVowels(string s, int k) 
    {
        int n=s.size();
        int ans=0;
        int left=0;
        int right=0;
        int curr=0;
        while(right<n)
        {
            if(right<k)
            {
                curr+=check(s[right]);
                ans=curr;
            }
            else
            {
                curr-=check(s[left]);
                curr+=check(s[right]);
                ans=max(ans,curr);
                left++;
            }
            right++;
        }
        return ans;
    }
};
