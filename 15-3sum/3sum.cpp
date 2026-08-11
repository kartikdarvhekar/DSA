class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>> ans;
        int n = nums.size();
        
        // Step 1: Sort the array to easily manage duplicates and use two pointers
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Skip duplicate elements for the 'i' pointer
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 2: Use two pointers (j and k) to find the remaining sum
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0) {
                    j++; // We need a larger sum, move left pointer right
                } else if (sum > 0) {
                    k--; // We need a smaller sum, move right pointer left
                } else {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    
                    // Skip duplicate elements for the 'j' pointer
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    
                    // Skip duplicate elements for the 'k' pointer
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
        }
     

    
};