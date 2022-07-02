class Solution 
{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        deque<int>st;
        stack<int>san;
        int count=0;
        for(int i=0;i<students.size();i++)
        {
            st.push_back(students[i]);
        }
        for(int i=sandwiches.size()-1;i>=0;i--)
        {
            san.push(sandwiches[i]);
        }
        while(!st.empty() && !san.empty())
        {
            if(st.front()==san.top())
            {
                count=0;
                san.pop();
                st.pop_front();
            }
            else
            {
                count++;
                st.push_back(st.front());
                st.pop_front();
                if(count>st.size())
                {
                    return st.size();
                }
            }
        }
        return 0;

    }
};
