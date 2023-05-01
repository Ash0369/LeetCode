class Solution 
{
public:
    double average(vector<int>& salary) 
    {
        sort(salary.begin(),salary.end());
        int tot=accumulate(salary.begin(),salary.end(),0);
        tot=tot-salary[0]-salary[salary.size()-1];
        
        double ans=(1.0*tot)/(salary.size()-2);
        
        return ans;
    }
};
