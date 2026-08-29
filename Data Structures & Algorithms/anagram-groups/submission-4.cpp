class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;  // Not reserving buckets - dynamic size
        for (const string &str : strs) {
            int counts[26] = {0};
            for (const char c : str) {  // Size to char(1) < &pointer(8)
                ++counts[c - 'a'];
            }
            string ints = "";  // Converting array to tuple key
            ints.reserve(26);
            for (int i : counts) {
                ints.push_back(i);
            }
            freq[ints].push_back(move(str));  // Avoid copying: O(1)
        }

        vector<vector<string>> values;
        values.reserve(freq.size());
        for (const auto &pair : freq) {
            values.push_back(pair.second);
        }
        return values;
    }
};
