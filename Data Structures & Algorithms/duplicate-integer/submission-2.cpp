class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
      // nums = [1, 2, 3, 3]
      for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                  if (nums[i] == nums[j]) {
                        return true;
                  }
            }
      }
      return 0;
    }
};