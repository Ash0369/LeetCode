class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int m=mainTank;
        int a=additionalTank;
        int ans=0;
        while(m>0)
        {
            if(m>=5)
            {
                ans+=50;
                m=m-4;
                a--;
                if(a<0)
                {
                    m--;
                }
            }
            else
            {
                ans+=10*m;
                break;
            }
        }
        return ans;
    }
};
