class Solution {
public:

    bool solve(vector<vector<char>>& s,
               vector<vector<vector<int>>>& dp,
               int i, int j, int balance) {

        int row = s.size();
        int col = s[0].size();

        if (s[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        if (balance > row + col)
            return false;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        if (i == row - 1 && j == col - 1)
            return dp[i][j][balance] = (balance == 0);

        bool ans = false;

        if (j + 1 < col)
            ans = solve(s, dp, i, j + 1, balance);

        if (!ans && i + 1 < row)
            ans = solve(s, dp, i + 1, j, balance);

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& s) {

        int row = s.size();
        int col = s[0].size();

        if (s[0][0] == ')')
            return false;

        if (s[row - 1][col - 1] == '(')
            return false;

        // Number of cells in path must be even
        if ((row + col - 1) % 2 != 0)
            return false;

        vector<vector<vector<int>>> dp(
            row,
            vector<vector<int>>(
                col,
                vector<int>(row + col + 1, -1)
            )
        );

        return solve(s, dp, 0, 0, 0);
    }
};