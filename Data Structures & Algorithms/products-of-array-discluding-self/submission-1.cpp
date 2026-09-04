class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        int prod = 1;
        int zeros = 0;
        int idx = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
                zeros++;
            }
            else {
                 prod *= nums[i];
            }
        }

        if (zeros >= 2) {
            return res;
        }   
        if (zeros == 1) {
            res[idx] = prod;
            return res;
        }
        for (int i = 0; i < n; ++i) {
            res[i] = prod/nums[i];
        }
        return res;
    }
};
