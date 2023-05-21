#define ll long long
bool check(string &s,int index,int n,int prev)
{
    if(index==s.size())
    {
        string temp=s.substr(prev,index-prev);
        int val=0;
        if(temp.size()>0)
        {
            val=stoi(temp);
        }
        return n==val;
    }
    bool a=check(s,index+1,n,prev);
    string temp=s.substr(prev,index-prev+1);
    
    int val=stoi(temp);
    bool b=check(s,index+1,n-val,index+1);
    return a|b;
}
class Solution 
{
public:
    int punishmentNumber(int n) 
    {
        ll int ans=0;
        for(int i=1;i<=n;i++)
        {
            string s=to_string(i*i);
            if(check(s,0,i,0))
            {
                ans+=i*i;
            }
        }
        return ans;
    }
};
