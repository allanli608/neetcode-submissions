class Solution {

public:

    bool isInterleave(string s1, string s2, string s3) {
    /* 
        dp: 
        rows: size of string a
        cols: size of string b
        dp[row][col]: consuming row chars of string a and 
        col chars of string b, can we generate the first row + col entries of c?
    */
    if (s1.size() + s2.size() != s3.size()) {
            return false;
    }

    vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            if (i == 0 && j == 0) continue;
            bool good = false;
            if (i - 1 >= 0 && dp[i - 1][j]) {
                good |= s3[i + j - 1] == s1[i - 1];
            }
            if (j - 1 >= 0 && dp[i][j - 1]) {
                good |= s3[i + j - 1] == s2[j - 1];
            }
            dp[i][j] = good;
        }
    }

    return dp[s1.size()][s2.size()];

    }
};
