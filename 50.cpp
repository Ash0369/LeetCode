double calc(double x,long int n)
{
    if(n==0)
        return 1;
    double res=calc(x,n/2);
    if(n%2==0)
    {
        return res*res;
    }
    return x*res*res;
}
class Solution 
{
public:
    double myPow(double x,int n) 
    {
        double res=calc(x,abs(n));
        if(n>0)
            return res;
        return (1.0/res);
    }
};
