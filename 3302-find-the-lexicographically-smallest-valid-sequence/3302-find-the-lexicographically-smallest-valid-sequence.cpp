class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
           
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = position of the latest occurrence
        // of word2[j] that can be used.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Match word2 from RIGHT to LEFT
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // We can use at most ONE mismatch
        bool canSkip = true;

        j = 0;

        // Now build answer from LEFT to RIGHT
        for (i = 0; i < n && j < m; i++) {

            // Normal matching character
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Use our one mismatch
            else if (canSkip &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;
                canSkip = false;
            }
        }

        // Couldn't match all characters
        if (j != m)
            return {};

        return ans;
    }
};