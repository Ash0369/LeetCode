class Solution 
{
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        vector<int>ans;
        int iter=num.size()-1;
        int carry=0;
        while(k>0 || iter>=0)
        {
            int ele=k%10;
            int toadd=ele;
            if(iter>=0)
            {
                toadd+=num[iter];
            }
            toadd+=carry;
            iter--;
            k=k/10;
            ans.push_back(toadd%10);
            carry=toadd/10;
        }
        if(carry!=0)
        {
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
