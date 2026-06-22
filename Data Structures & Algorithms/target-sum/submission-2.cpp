class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        vector<unordered_map<int, int>> dp(nums.size(), unordered_map<int, int>());
        dp[0][nums[0]] += 1;
        dp[0][-nums[0]] += 1;

        for (int i = 1; i < nums.size(); ++i) {
            for (auto const &[key, value] : dp[i-1]) {
                int new_res_p = key + nums[i];
                int new_res_n = key - nums[i];
                dp[i][new_res_p] += value;
                dp[i][new_res_n] += value;
            }
        }

        for (auto m : dp) {
            cout << "[";
            for (auto &[a, b] : m) {
                cout << "(" << a << ", " << b << "), ";
            }
            cout << "]" << endl;
        }

        return dp[nums.size() - 1][target];
    }
};
