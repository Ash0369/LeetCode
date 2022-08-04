void swap(vector<int>&a,vector<int>&b)
{
    vector<int>c=b;
    b=a;
    a=c;
}
int max_score=INT_MIN;
int combality(vector<int>&a,vector<int>&b)
{
    int score=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==b[i])
        {
            score++;
        }
    }
    return score;
}
void per(vector<vector<int>>&students,int index,vector<vector<int>>&mentors,int score)
{
    if(index==students.size())
    {
        max_score=max(max_score,score);
        return;
    }
    for(int i=index;i<students.size();i++)
    {
        swap(students[index],students[i]);
        int x=combality(students[index],mentors[index]);
        score=score+x;
        per(students,index+1,mentors,score);
        score=score-x;
        swap(students[index],students[i]);
    }
}
class Solution 
{
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) 
    {
        max_score=INT_MIN;
        per(students,0,mentors,0);
        return max_score;
    }
};
