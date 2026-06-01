class Solution {
public:

    vector<vector<int>> dir = { {0 , 1} , { 1 , 0} , { -1 , 0} , {0 , -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int m = grid.size();
        // if (m == 0) return;
        int n = grid[0].size() ;

        queue<pair<int,int>> q ;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 0){
                    q.push({i , j});
                }
            }
        }

        int distance = 0;

        while(!q.empty()){

            int size = q.size();

            for(int i = 0; i < size; i++){

                int r = q.front().first ;
                int c = q.front().second ;

                q.pop() ;

                for(auto it : dir){

                    int nr = r + it[0];
                    int nc = c + it[1];

                    if(nr >= m || nr < 0 || nc >= n || nc < 0 || grid[nr][nc] != INT_MAX) continue ;

                    grid[nr][nc] = distance + 1 ;
                    q.push({ nr , nc}) ;
                }
            }

            distance++;
        }
    }
};