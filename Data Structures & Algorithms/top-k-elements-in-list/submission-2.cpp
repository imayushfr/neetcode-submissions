class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (const int num : nums) {
            freqs[num]++;
        }

        // Bucket sort from freq 1 to n into list
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto &freq : freqs) {
            buckets[freq.second].push_back(freq.first);
        }

        vector<int> res;
        for (int i = buckets.size() - 1; i > 0; --i) {
             for (int n : buckets[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
    }
};
