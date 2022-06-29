class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        deque<int>dire;
        deque<int>radiant;
        int n=senate.length();
        int pos=n;
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')
            {
                radiant.push_back(i);
            }
            else
            {
                dire.push_back(i);
            }
        }
        char last;
        int rcount=0;
        int dcount=0;
        while(!dire.empty() && !radiant.empty())
        {
            int r_top=radiant.front();
            int d_top=dire.front();
            if(r_top<d_top)
            {
                dire.pop_front();
                radiant.push_back(pos);
                pos++;
                radiant.pop_front();
            }
            else
            {
                radiant.pop_front();
                dire.push_back(pos);
                pos++;
                dire.pop_front();
            }
        }
        if(!dire.empty())
        {
            return "Dire";
        }
        return "Radiant";
    }
};
