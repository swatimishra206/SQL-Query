class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // First string ko prefix maan lo
        string prefix = strs[0];

        // Baaki strings ke saath compare karo
        for (int i = 1; i < strs.size(); i++) {

            // Jab tak current string mein prefix nahi milta
            while (strs[i].find(prefix) != 0) {

                // Prefix ka last character remove karo
                prefix.pop_back();

                // Agar common prefix nahi bacha
                if (prefix.empty()) {
                    return "";
                }
            }
        }

        // Final longest common prefix return karo
        return prefix;
    }
};