class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int, int>> pacificQ;
        queue<pair<int, int>> atlanticQ;

        for (int c = 0; c < n; c++) {
            pacificQ.emplace(0, c);
            pacific[0][c] = true;

            atlanticQ.emplace(m - 1, c);
            atlantic[m - 1][c] = true;
        }

        for (int r = 0; r < m; r++) {
            pacificQ.emplace(r, 0);
            pacific[r][0] = true;

            atlanticQ.emplace(r, n - 1);
            atlantic[r][n - 1] = true;
        }

        bfs(heights, pacificQ, pacific);
        bfs(heights, atlanticQ, atlantic);

        vector<vector<int>> res;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) res.push_back({r, c});
            }
        }
        return res;
    }

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        int m = heights.size();
        int n = heights[0].size();

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(const auto [dr,dc] : dir){
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && 
                !visited[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    q.emplace(nr,nc);
                    visited[nr][nc] = true;
                }
            }
        }


    }
};
