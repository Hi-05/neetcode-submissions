class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &vis){

        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = 1;
        queue<vector<int>> q ;

        q.push({i,j});

        while(!q.empty()){

            int r = q.front()[0];
            int c = q.front()[1];

            q.pop();

            for(auto it : dir){

                int nr = r + it[0];
                int nc = c + it[1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1' && !vis[nr][nc] ){

                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        vector<vector<int>> vis(m,vector<int> (n,0));

        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == '1' && vis[i][j] == 0){
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
