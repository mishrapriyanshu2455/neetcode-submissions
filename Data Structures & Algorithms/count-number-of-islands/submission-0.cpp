class Solution {
public:

int r,c;

    int row[4]={1,-1,0,0};
    int col[4]={0,0,-1,1};

    bool valid(int i,int j)
    {
        return (i>=0 && i<r && j>=0 && j<c);
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>&vis, queue<pair<int,int>>&q,int i,int j)
    {
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();


            for(int k=0;k<4;k++)
            {
                if(valid(i+row[k],j+col[k]) && grid[i+row[k]][j+col[k]]=='1' && !vis[i+row[k]][j+col[k]])
                {
                    vis[i+row[k]][j+col[k]]=1;
                    q.push({i+row[k],j+col[k]});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        r=grid.size();
        c=grid[0].size();

        queue<pair<int,int>>q;
        vector<vector<bool>>vis(r,vector<bool>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                   bfs(grid,vis,q,i,j);
                   ans++;
                }
            }
        }

        return ans;
    }
};
