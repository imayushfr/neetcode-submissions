class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> prev;  // Value: Index
      int n = nums.size();
      prev.reserve(n);

      for (int i = 0; i < n; ++i) {
        int diff = target - nums[i];
        if (prev.count(diff)) {
          return {prev[diff], i};
        }
        prev[nums[i]] = i;
      }
    }
};
