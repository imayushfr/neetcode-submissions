class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string s : strs) {  // O(n) time
            encoded += to_string(s.size()) + "#" + s;  // O(m) space
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;  // O(n) space
        int i = 0;
        int n = s.size();

        while (i < n) {
            // O(m) time
            int j = i;
            while (s[j] != '#') {
                ++j;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            decoded.push_back(s.substr(i, length));
            j = i + length;
            i = j;
        }
        return decoded;
    }
};
