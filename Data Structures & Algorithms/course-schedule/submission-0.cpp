class Solution {
public:

    bool dfs(vector<vector<int>>&adj, vector<int>&vis,int node,vector<int>&path)
    {
        vis[node]=1;
        path[node]=1;

        for(int neigh : adj[node])
        {
            if(path[neigh]) return true;

          else if(!vis[neigh]){
            if(dfs(adj,vis,neigh,path))
            return true;}
        }

        path[node]=0;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int>path(n,0);
        vector<int>vis(n,0);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            if(dfs(adj,vis,i,path))
            return false;
        }
        return true;
    }
};
