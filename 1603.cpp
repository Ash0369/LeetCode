class ParkingSystem 
{
public:
    int b,m,s;
    ParkingSystem(int big, int medium, int small) 
    {
        b=big;
        m=medium;
        s=small;
    }
    
    bool addCar(int carType) 
    {
        if(carType==3)
        {
            s--;
            return s>=0;
        }
        if(carType==2)
        {
            m--;
            return m>=0;
        }
        
        b--;
        return b>=0;
    }
};
