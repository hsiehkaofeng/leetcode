class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int head = 0;
        // the second element in m represents the position of the char.
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++) {
            if(m.count(s[i]) != 0) {
                head = max(m[s[i]] + 1, head);
            }
            // update the position of s[i] in m
            m[s[i]] = i;
            count = max(count, i - head + 1);
        }
        return count;
    }
};