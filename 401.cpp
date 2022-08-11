class Solution 
{
public:
    vector<string> readBinaryWatch(int turnedOn) 
    {
        vector<string>s;
        for(int hour=0;hour<12;hour++)
        {
            for(int minute=0;minute<60;minute++)
            {
                if(__builtin_popcount(hour)+__builtin_popcount(minute)==turnedOn)
                {
                    string minute_string=to_string(minute);
                    if(minute<10)
                    {
                        minute_string="0"+to_string(minute);
                    }
                    string temp=to_string(hour)+':'+minute_string;
                    s.push_back(temp);
                }
            }
        }
        return s;
    }
};
