#define ll long long

bool check(int num1,int num2,ll int op)
{
    ll int n=(1LL*num1)-(1LL*num2*op);
    if(n<0)
        return false;
    int st=__builtin_popcountll(n);
    
    if(st==0)
    {
        return op==0;
    }
    if(st==op)
    {
        return true;
    }
    return n>=op && op>=st;
}
class Solution 
{
public:
    int makeTheIntegerZero(int num1, int num2) 
    {
        ll int ans=0;
        for(int i=0;i<=100;i++)
        {
            if(check(num1,num2,i))
            {
                return i;
            }
        }
        return -1;
    }
};
