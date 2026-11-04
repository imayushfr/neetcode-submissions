class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // For O(1) lookup time and remove duplicates; O(n) space
        unordered_set<int> unique(nums.begin(), nums.end());
        int length = 0;

        for (int uni : unique) {  // O(n^2) time
            // Find beginning of the sequences, then only start
            if (!unique.count(uni - 1)) {
                int streak = 1;
                // If false, terminate
                while (unique.count(uni + 1)) {
                    streak++;
                    uni++;
                }
                length = max(length, streak);
            }
        }
        return length;
    }
};
