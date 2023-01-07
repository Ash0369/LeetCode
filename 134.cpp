
class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n=gas.size();
        int curr_gas=0;
        int tot_gas=0;
        int tot_cost=0;
        int st=0;
        for(int i=0;i<n;i++)
        {
            tot_gas+=gas[i];
            tot_cost+=cost[i];
            
            curr_gas+=gas[i]-cost[i];
            
            if(curr_gas<0)
            {
                st=i+1;
                curr_gas=0;
            }
        }
        
        if(tot_gas>=tot_cost)
            return st;
        return -1;
        
    }
};
