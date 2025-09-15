class Solution {
public:
    int canBeTypedWords(string text, string broken) {
        stringstream ss(text);
        unordered_set<char> st(broken.begin(), broken.end());

        int count = 0;
        string token;

        while (ss >> token) {
            bool canType = true;

            for (char c : token) {
                if (st.count(c)) {
                    canType = false;
                    break;
                }
            }

            if (canType) count++;
        }

        return count;
    }
};
