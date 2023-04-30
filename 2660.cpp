class Solution 
{
public:
    int isWinner(vector<int>& player1, vector<int>& player2) 
    {
        int a=0;
        int b=0;
        for(int i=0;i<player1.size();i++)
        {
            a=a+player1[i];
            if((i-1>=0 && player1[i-1]>=10) || (i-2>=0 && player1[i-2]>=10))
            {
                a=a+player1[i];
            }
            
            b=b+player2[i];
            if((i-1>=0 && player2[i-1]>=10) || (i-2>=0 && player2[i-2]>=10))
            {
                b=b+player2[i];
            }
        }
        
        if(a==b)
            return 0;
        if(a>b)
            return 1;
        return 2;
    }
};
