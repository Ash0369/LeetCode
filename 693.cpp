//Method-1 : 

class Solution 
{
public:
    bool hasAlternatingBits(int n) 
    {
        bool last;
        if(n%2==0)
        {
            //even
            last=true;
        }
        else
        {
            last=false;
        }
        while(n>0)
        {
            int res=(n&1);
            if(res==1)
            {
                if(last==true)
                    return false;
                last=true;
            }
            else
            {
                if(last==false)
                    return false;
                last=false;
            }
            n=n>>1;
        }
        return true;
    }
};


//Method-2 : 
//https://leetcode.com/problems/binary-number-with-alternating-bits/discuss/2680216/C%2B%2B-or-two-line-or-XOR

class Solution 
{
public:
    bool hasAlternatingBits(int n) 
    {
        long long a=(n^(n>>1)); //Right shift n xor with n
        
        //If alernating bits diff then n will be like 1111..
        
        //Now if we add 1 and take and operation then it will be zero
        
        return !(a&(a+1));
    }
};
