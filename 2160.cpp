class Solution 
{
public:
    int minimumSum(int num) 
    {
        vector<int>vec;
        while(vec.size()!=4)
        {
            vec.push_back(num%10);
            num=num/10;
        }
        
        sort(vec.begin(),vec.end());
        
        int n1=vec[0];
        int n2=vec[1];
        
        n1=(n1*10)+vec[2];
        n2=(n2*10)+vec[3];
        
        return n1+n2;
    }
};
