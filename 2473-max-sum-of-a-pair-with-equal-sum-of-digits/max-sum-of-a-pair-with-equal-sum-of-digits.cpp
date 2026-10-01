class Solution {
public:
    int check(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        // Map to store: {digit_sum -> maximum_number_with_that_sum}
        unordered_map<int, int> max_val_for_sum; 
        int max_sum = -1;

        for (int i = 0; i < nums.size(); i++) {
            int digit_sum = check(nums[i]);

            // If we have already seen this digit sum, calculate the pair sum
            if (max_val_for_sum.count(digit_sum)) {
                int current_pair_sum = nums[i] + max_val_for_sum[digit_sum];
                max_sum = max(max_sum, current_pair_sum);
            }

            // Update the map to hold the largest number found for this digit sum
            max_val_for_sum[digit_sum] = max(max_val_for_sum[digit_sum], nums[i]);
        }

        return max_sum;
    }
};