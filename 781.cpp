//Method-1 : 

class Solution 
{
public:
    int numRabbits(vector<int>& answers) 
    {
        map<int,int>mp;
        for(auto x:answers)
        {
            mp[x+1]++;//As rabbit will not count itself so done x+1
        }
        int rabbit=0;
        for(auto x:mp)
        {
            int grp=x.second/x.first;
            if(x.second%x.first!=0)
                grp++;
            rabbit+=(grp)*x.first;
        }
        return rabbit;
    }
};

//Method-2 :

class Solution 
{
public:
    int numRabbits(vector<int>& answers) 
    {
        int cnt=1;
        int extra=0;
        sort(answers.begin(),answers.end());
        for(int i=0;i<answers.size();i++)
        {
            if(i==answers.size()-1 || answers[i]!=answers[i+1])
            {
                int temp=cnt%(answers[i]+1);
                if(temp)
                {
                    extra+=answers[i]+1-temp;
                }
                cnt=1;
            }
            else
            {
                cnt++;
            }
        }
        return answers.size()+extra;
    }
};
