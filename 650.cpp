int paste(int present,int last,int n)
{
    if(present>n)
        return 1e9;
    if(present==n)
        return 0;
    
    int a=2+paste(present*2,present,n);
    int b=1e9;
    if(last>0)
       b=1+paste(present+last,last,n);
    return min(a,b);
}
class Solution 
{
public:
    int minSteps(int n) 
    {
        return paste(1,0,n);
    }
};
