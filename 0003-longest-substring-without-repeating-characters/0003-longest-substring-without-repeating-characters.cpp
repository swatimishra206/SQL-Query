class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0;
        int maxLen = 0;

        vector<int> lastSeen(256, -1);

        for (int end = 0; end < n; end++) {
            char ch = s[end];

            // Agar character current window mein pehle aa chuka hai
            if (lastSeen[ch] >= start) {
                start = lastSeen[ch] + 1;
            }

            // Current character ka latest index update karo
            lastSeen[ch] = end;

            // Window ki length
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};