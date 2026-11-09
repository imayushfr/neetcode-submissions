class Solution {
public:
    bool isPalindrome(string s) {
        string alpha_num;  // Empty string
        for (char &c : s) {
            if (isalnum(c)){
                alpha_num.push_back(toupper(c));
            }
        }

        int n = alpha_num.length();
        int l = n / 2;
        for (int i = 0; i < l; ++i) {
            if (alpha_num[i] != alpha_num[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
