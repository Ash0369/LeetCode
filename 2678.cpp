class Solution 
{
public:
    int countSeniors(vector<string>& details) 
    {
        int ans=0;
        for(auto x:details)
        {
            string s=x;
            int age=stoi(s.substr(11,2));
            if(age>60)
            {
                ans++;
            }
        }
            return ans;
    }
};
