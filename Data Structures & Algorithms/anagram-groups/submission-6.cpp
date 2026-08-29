class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;  // Not reserving buckets - dynamic size
        for (const string &str : strs) {
            int counts[26] = {0};
            for (const char c : str) {  // Size to char(1) < &pointer(8)
                ++counts[c - 'a'];
            }
            string key = to_string(counts[0]);  // Converting array to tuple key
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(counts[i]);
            }
            freq[key].push_back(str);
        }

        vector<vector<string>> values;
        values.reserve(freq.size());
        for (const auto &pair : freq) {
            values.push_back(pair.second);
        }
        return values;
    }
};
