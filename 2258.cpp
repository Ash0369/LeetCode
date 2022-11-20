bool cross(vector<vector<int>>grid,int row,int col,int pass)
{
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    queue<pair<int,int>>q;
    //Move all fire in queue
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==1)
            {
                q.push({i,j});
            }
        }
    }
    
    //Till waiting time fire will spread to adjacent cells
    for(int i=1;i<=pass;i++)
    {
        int sz=q.size();
        for(int j=0;j<sz;j++)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny]==0)
                {
                    grid[nx][ny]=1;
                    q.push({nx,ny});
                    if(nx==row-1 && ny==col-1)
                        return false;//Fire has burnt safe house before person can reach
                }
            }
        }
    }
    
    
    queue<pair<int,int>>person;
    person.push({0,0});
    while(!person.empty())
    {
        int sz=q.size();
        int p=person.size();
        //First Move person
        for(int i=0;i<p;i++)
        {
            //Move each person
            int x=person.front().first;
            int y=person.front().second;
            person.pop();
            if(grid[x][y]==1)
                continue;//This person burnt by fire so cannot move
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                
                if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny]==0)
                {
                    grid[nx][ny]=3;
                    person.push({nx,ny});
                    if(nx==row-1 && ny==col-1)
                        return true;
                }
            }
        }
        //Now move fire
        for(int i=0;i<sz;i++)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<row && ny<col && (grid[nx][ny]==0 || grid[nx][ny]==3))
                {
                    //If person or grass then fire will burn it.
                    grid[nx][ny]=1;
                    q.push({nx,ny});
                    if(nx==row-1 && ny==col-1)
                        return false;//Fire has burnt safe house before person can reach
                }
            }
        }
        
    }
    return false;//Person was burnt
}
class Solution 
{
public:
    int maximumMinutes(vector<vector<int>>& grid) 
    {
        int row=grid.size();
        int col=grid[0].size();
        
        int low=0;
        int high=row*col;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(cross(grid,row,col,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(ans==(row*col))
            return 1e9;
        return ans;
    }
};
