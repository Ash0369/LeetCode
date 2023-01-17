int dfs(vector<Employee*>employees,unordered_map<int,int>&mp,int id)
{
    int index=mp[id];
    int val=employees[index]->importance;
    for(auto x:employees[index]->subordinates)
    {
        val+=dfs(employees,mp,x);
    }
    return val;
}
class Solution 
{
public:
    int getImportance(vector<Employee*>employees, int id) 
    {
        int n=employees.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[employees[i]->id]=i;
        }
        return dfs(employees,mp,id);
    }
};
