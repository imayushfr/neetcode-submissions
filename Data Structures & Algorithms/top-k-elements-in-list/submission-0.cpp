class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;  // O(n) space
        for (const int i : nums) {  // O(n) time
            freqs[i]++;  // Can't sort by values
        }

        vector<pair<int, int>> counts;  // O(n) space
        for (const auto &freq : freqs) {  // O(n) time
            counts.push_back({freq.second, freq.first});  // [freq, num]
        }

        sort(counts.rbegin(), counts.rend());  // Sorted by freq

        vector<int> arr(k);  // O(1)
        for (int i = 0; i < k; ++i) {  // O(1)
            arr[i] = counts[i].second;
        }
        return arr;
    }
};
