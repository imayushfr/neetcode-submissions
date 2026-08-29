class Solution {
public:
    bool isAnagram(string s, string t) {
      size_t n = s.length();
      if (n != t.length()) {  // O(1)
            return false;
      }

      int counts[26] = {0};  // O(1)
      for (size_t i = 0; i < n; ++i) {  // O(n)
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
      }

      for (int count : counts) {  // O(1)
            if (count != 0) {
                  return false;
            }
      }
      return true;
    }
};
