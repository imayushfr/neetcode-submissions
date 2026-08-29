class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> complement;  // nums[i], idx
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        int diff = target - nums[i];
        if (complement.count(diff)) {
          return {complement[diff], i};
        }
        complement[nums[i]] = i;

        // if (nums[i] + complement[nums[i]] == target) {
        //   idx1 = i;
        // }
        // if (nums[i] == complement[nums[idx1]]) {
        //   return {idx1, i};
        // }
      }
      
      // int idx2 = 0;
      // for (int j = 0; j < n; ++j) {
      //   if (nums[j] == complement[nums[idx1]]) {
      //     idx2 = j;
      //   }
      // }

    //   for (auto pair : complement) {
    //     cout << pair.first << ": " << pair.second << endl;
    // }
    // return {};
    }
};
