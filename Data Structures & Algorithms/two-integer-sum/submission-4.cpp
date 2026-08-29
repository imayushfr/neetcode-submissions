class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> prev;  // Value: Index
      int n = nums.size();
      prev.reserve(n);

      for (int i = 0; i < n; ++i) {
        int cur = nums[i];
        int diff = target - cur;
        auto it = prev.find(diff);
        if (it != prev.end()) {  // If found
          return {it->second, i};
        }
        prev.emplace(cur, i);
      }
    }
};
