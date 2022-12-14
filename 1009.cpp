class Solution 
{
public:
    int bitwiseComplement(int n) 
    {
        if(n==0)
            return 1;
        int x=log2(n);
        int bits=x+1;
        int full_value=pow(2,bits)-1;
        return full_value-n;
    }
};
