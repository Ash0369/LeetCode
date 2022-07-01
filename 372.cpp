long long int bin_exp_b_large(long long int a,long long int b,long long int m)
{
    //Make a smaller
    a=a%m;
    long long int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b=(b>>1)%m;
    }
    return ans;
}
class Solution {
public:
    int superPow(int a, vector<int>& b) 
    {
        //Form b from the array
        long long int k=1;
        long long int res=0;
        long long int m=1140;
        for(int i=b.size()-1;i>=0;i--)
        {
            long long int temp=(b[i]*k)%m;
            res=(res+temp)%m;
            k=(k*10)%m;
        }
        return bin_exp_b_large(a,res,1337);

    }
};
