class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int, vector<pair<int, int>>> coords;
        priority_queue<int, vector<int>, greater<int>> dist;
        vector<vector<int>> res;

        for (const auto &point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            coords[distance].push_back({point[0], point[1]});
            dist.push(distance);
        }

        for (int i = 0; i < k; ++i) {
            int d = dist.top();
            auto coord = coords[d].back();
            coords[d].pop_back();
            res.push_back({coord.first, coord.second});
            dist.pop();
        }

        return res;


    }
};
