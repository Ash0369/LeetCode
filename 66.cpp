class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int>ans;
        int n=digits.size();
        digits[n-1]++;
        for(int i=n-1;i>=0;i--)
        {
            if(digits[i]==10)
            {
                if(i>0)
                {
                    digits[i-1]++;
                    ans.push_back(0);
                }
                else{
                    ans.push_back(0);
                    ans.push_back(1);
                }
            }
            else{
                ans.push_back(digits[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
