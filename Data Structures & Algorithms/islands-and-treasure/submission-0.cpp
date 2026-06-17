class Solution {

struct Data {
    int x;
    int y;
    int distance;
};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf = 2147483647;
        std::queue<Data> q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0 ; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j, 0});
                } 
            }
        }

        while (!q.empty()) {
            Data d = q.front();
            q.pop();
            int res = grid[d.x][d.y];
            if (res == inf || res == 0) {
                if (res == inf) {
                    grid[d.x][d.y] = d.distance;
                }
                if (d.x < grid.size() - 1) {
                    q.push({d.x + 1, d.y, d.distance + 1});
                } 
                if (d.x > 0) {
                    q.push({d.x - 1, d.y, d.distance + 1});
                } 
                if (d.y < grid[0].size() - 1) {
                    q.push({d.x, d.y + 1, d.distance + 1});
                } 
                if (d.y > 0) {
                    q.push({d.x, d.y - 1, d.distance + 1});
                } 
            }
        }

    }
};
