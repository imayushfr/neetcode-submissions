class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;
        freq.reserve(strs.size());
        for (const string &str : strs) {
            int counts[26] = {0};
            for (const char c : str) {
                ++counts[c - 'a'];
            }
            string ints = "";
            for (int i : counts) {
                ints.push_back(i);
            }
            freq[ints].push_back(str);
        }
        vector<vector<string>> values;
        for (const auto &pair : freq) {
            values.push_back(pair.second);
        }
        return values;
    }
};
