class Solution {
public:
    int minsum(vector<vector<int>>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i == arr.size()) return 0;
        if (dp[i][j] != INT_MAX) return dp[i][j]; // Return cached result
        
        int down = minsum(arr, i + 1, j, dp);
        int diag = minsum(arr, i + 1, j + 1, dp);
        
        return dp[i][j] = arr[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return minsum(arr, 0, 0, dp);
    }
};