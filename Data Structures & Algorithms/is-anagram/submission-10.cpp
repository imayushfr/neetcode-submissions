class Solution {
public:
    bool isAnagram(string s, string t) {
      int n = s.size();
      if (n != t.size()) {  // O(1)
            return false;
      }

      vector<int> counts(26, 0);  // O(1)
      for (int i = 0; i < n; i++) {  // O(n)
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
      }

      for (int i : counts) {  // O(1)
            if (i != 0) {
                  return false;
            }
      }
      return true;
    }
};
