class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int>res(n);  // Default to zeroes

        // Prefix pass
        res[0] = 1;
        for (int i = 1; i < n; ++i) {
            res[i] = nums[i - 1] * res[i - 1];
        }
 
        // Suffix pass over prefix = result
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            // Can't do the above way because 
            // we need to keep track of suffix
            res[i] = res[i] * suffix;  // Pref * Suff
            suffix = suffix * nums[i];  // Updating suffix
        }
        // cout << suffix << endl;

        return res;
    }
};
