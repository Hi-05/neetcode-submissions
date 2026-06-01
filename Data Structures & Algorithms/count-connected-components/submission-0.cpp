class Solution {
public:

    void bfs(int node , vector<vector<int>> &adj , vector<int> &vis){

        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){

            int curr = q.front();
            q.pop();


            for(auto it : adj[curr]){

                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it) ;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n) ;
        for(int i = 0; i < edges.size() ; i++){

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u) ;
        }

        vector<int> vis(n,0) ;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            
            if(!vis[i]){
                cnt++;
                bfs(i,adj,vis) ;
            }
        }

        return cnt ;
    }
};
