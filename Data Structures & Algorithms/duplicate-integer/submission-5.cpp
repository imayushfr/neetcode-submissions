class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {  // Passing by reference, instead of copying array
      unordered_set<int> seen;  // Hash set
      seen.reserve(nums.size());  // Pre-allocate buckets to prevent dynamic rehashing
      for (int num : nums) {
        if (!seen.insert(num).second) {  // Returns <iterator, bool>
          return true;
        }
      }
      return false;
    }
};