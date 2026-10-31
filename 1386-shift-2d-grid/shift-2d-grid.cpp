#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Handle cases where k is greater than the total number of elements
        k = k % total;
        
        // Initialize the result grid with the same dimensions
        std::vector<std::vector<int>> ans(m, std::vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Calculate the new 1D index
                int new_idx = (i * n + j + k) % total;
                
                // Map back to 2D coordinates
                int x = new_idx / n;
                int y = new_idx % n;
                
                ans[x][y] = grid[i][j];
            }
        }
        
        return ans;
    }
};