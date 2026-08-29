class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> list;  // Sorted: Array
        list.reserve(strs.size());
        for (const string& str : strs) {  // Pass by reference
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            list[sorted].push_back(str);
        }

        vector<vector<string>> values;
        values.reserve(list.size());
        for (const auto& pair : list) {  // Pass by reference
            values.push_back(pair.second);
        }
        return values;
    }
};
