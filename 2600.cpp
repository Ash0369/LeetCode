class Solution 
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) 
    {
        int ans=0;
        ans=min(k,numOnes);
        if(k<=(numOnes+numZeros))
        {
            return ans;
        }
        k=k-numOnes-numZeros;
        ans=ans-k;
        return ans;
        
    }
};
