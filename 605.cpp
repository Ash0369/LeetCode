class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int m=flowerbed.size();
        int ans=0;
        for(int i=0;i<flowerbed.size();i++)
        {
            if((i!=0 && flowerbed[i-1]==1 ) || (i!=m-1 && flowerbed[i+1]==1) || flowerbed[i]==1)
            {
                
            }
            else
            {
                flowerbed[i]=1;
                ans++;
            }
        }
        return ans>=n;
    }
};
