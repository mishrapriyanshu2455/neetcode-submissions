class Solution {
public:

    bool dfs(vector<vector<int>>&adj,vector<int>&path,vector<int>&vis,int node,vector<int>&topo)
    {
        path[node]=1;
        vis[node]=1;

        for(int neigh : adj[node])
        {
            if(path[neigh]) return true;

            else if(!vis[neigh])
            {
                if(dfs(adj,path,vis,neigh,topo)) return true;
            }
        }    

            topo.push_back(node);
            path[node]=0;
            return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<int>path(n,0);

        vector<int>topo;
        for(int i=0;i<n;i++){

            if(!vis[i])
            if(dfs(adj,path,vis,i,topo))
            return {};
        }

        reverse(topo.begin(),topo.end());

        return topo;

    }
};
