class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
      int n = s.length();
      if (n != t.length()) {  // O(1)
            return false;
      }

      int counts[26] = {0};  // O(1)
      for (int i = 0; i < n; ++i) {  // O(n)
            ++counts[s[i] - 'a'];  // No return
            --counts[t[i] - 'a'];  // Values
      }

      for (int count : counts) {  // O(1)
            if (count != 0) {
                  return false;
            }
      }
      return true;
    }
};
