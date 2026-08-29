class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (const int i : nums) {
            freqs[i]++;
        }
        
        // Type of element, Under the hood container, Comparision rule
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (auto &freq : freqs) {
            min_heap.push({freq.second, freq.first});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};
