class Solution {
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        // if(!grid.empty()) return 0;
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == '1'){
                    bfs(r,c,grid);
                    islands++;
                }
            }
        }
        return islands;
    }

    void bfs(int r, int c, std::vector<vector<char>>& grid){
        std::queue<std::pair<int,int>> q;
        grid[r][c] = '0';
        q.emplace(r,c);
        
        while(!q.empty()){
            auto point = q.front();
            q.pop();
            int row = point.first , col = point.second;

            for(const auto [dx,dy] : directions){
                int nr = row + dx, nc = col + dy;
                if(nr >=0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1'){
                    q.emplace(nr,nc);
                    grid[nr][nc] = '0';
                }
            }

        }
    }
};
