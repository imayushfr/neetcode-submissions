class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> list;
        for (string str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            list[sorted].push_back(str);
        }

        vector<vector<string>> values;
        for (auto pair : list) {
            values.push_back(pair.second);
        }
        return values;
    }
};
