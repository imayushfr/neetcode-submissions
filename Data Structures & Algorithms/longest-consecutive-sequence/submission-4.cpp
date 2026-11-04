class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
         
        sort(nums.begin(), nums.end());  // O(nlogn) time; Ordering reduces repetition
        int length = 1;  // If only single element in array
        int n = nums.size();

        int i = 0;
        int streak = 1;
        while (i < n - 1) {  // O(n) time; Seg fault
            if (nums[i + 1] == nums[i] + 1) {
                streak++;
                length = max(length, streak);
            }
            else if (nums[i + 1] == nums[i]) {
                i++;
                continue;  // Skip this iteration
            }
            else {  // Breakpoint
                streak = 1;
            }
            i++; 
        }
        return length;
    }
};
