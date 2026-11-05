class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;  // All values initialized to 0
        int length = 0;

        // Union-Find
        for (int num : nums) {
            if (!mp[num]) {  // Don't count duplicates
                mp[num] = mp[num - 1] + mp[num + 1] + 1;
                // Only updating the left and right boundaries because 
                // now, any consecutive number can't come in between.
                mp[num - mp[num - 1]] = mp[num];
                mp[num + mp[num + 1]] = mp[num];  
                length = max(length, mp[num]);
            }
        }
        return length;
    }
};
