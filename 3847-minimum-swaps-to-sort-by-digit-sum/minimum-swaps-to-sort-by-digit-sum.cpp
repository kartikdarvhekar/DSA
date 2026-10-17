class Solution {
public:
    // Fix 1: Properly calculate digit sum without multiplying x by 10
    int ds(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // Store { {digit_sum, value}, original_index }
        vector<pair<pair<int, int>, int>> v(n);
        
        for (int i = 0; i < n; i++) {
            v[i] = {{ds(nums[i]), nums[i]}, i};
        }
        
        // Sort by digit sum first, then by value as tie-breaker
        sort(v.begin(), v.end());
        
        // Fix 2: Cycle detection / index swapping to count exact minimum swaps
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            // While the current element is not in its original index position
            while (v[i].second != i) {
                swap(v[i], v[v[i].second]);
                swaps++;
            }
        }
        
        return swaps;
    }
};