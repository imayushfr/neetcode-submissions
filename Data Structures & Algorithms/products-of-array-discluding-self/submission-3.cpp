class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);  // 'n' zeros
        vector<int> suffix(n);  // O(3n) space
        vector<int> res;

        prefix[0] = 1;
        for (int i = 1; i < n; ++i) {  // O(3n) time
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        suffix[n - 1] = 1;
        for (int i = n - 2; i > -1; --i) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            res.push_back( prefix[i] * suffix[i]);
        }
        return res;
    }
};
