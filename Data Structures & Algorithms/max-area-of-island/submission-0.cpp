class Solution {
    int dirc[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int res = 0;
        int ROW = grid.size();
        int COL = grid[0].size();

        for(int r = 0; r < ROW; r++){
            for(int c = 0; c < COL; c++){
                if(grid[r][c] == 1){
                    res = max(res,bfs(r,c,grid));
                }
            }
        }
        return res;
    }
    int bfs(int r, int c, std::vector<std::vector<int>>& grid){
        int res = 1;
        grid[r][c] = 0;

        std:queue<pair<int,int>> q;
        q.emplace(r,c);

        while(!q.empty()){
            auto point = q.front();
            int row = point.first, col = point.second;
            q.pop();

            for(const auto [dr,dc] : dirc){
                int nr = row + dr, nc = col + dc; 
                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1){
                    res += 1;
                    grid[nr][nc] = 0;
                    q.emplace(nr,nc);                    
                }
            }
        }
        return res;

    }
};
