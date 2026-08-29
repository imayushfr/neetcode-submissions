class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
      unordered_set<int> set;  // Hashset
      for (int num : nums) {
            if (set.count(num)) {
                  return true;
            }
            set.insert(num);
      }
      return 0;
    }
};