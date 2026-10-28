class Solution {
public:
    string convert(string s, int numRows) {

        // Agar sirf 1 row hai ya string chhoti hai
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Har row ke characters store karne ke liye
        vector<string> rows(numRows);

        int currentRow = 0;
        int direction = 1;  // 1 = neeche, -1 = upar

        // Har character ko correct row mein daalo
        for (char ch : s) {

            rows[currentRow] += ch;

            // First row par ho toh neeche jaana hai
            if (currentRow == 0) {
                direction = 1;
            }

            // Last row par ho toh upar jaana hai
            else if (currentRow == numRows - 1) {
                direction = -1;
            }

            // Next row par move karo
            currentRow += direction;
        }

        // Sabhi rows ko combine karo
        string ans = "";

        for (int i = 0; i < numRows; i++) {
            ans += rows[i];
        }

        return ans;
    }
};