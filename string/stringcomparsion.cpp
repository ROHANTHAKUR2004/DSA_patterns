class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        int i = 1;
        char curr_char = chars[0];
        int count = 1;

        while (i < n) {
            if (chars[i] == curr_char) {
                count++;
            } else {
                chars[idx++] = curr_char;
                if (count > 1) {
                    string cnt_str = to_string(count);
                    for (char c : cnt_str) {
                        chars[idx++] = c;
                    }
                }
                curr_char = chars[i];
                count = 1;
            }
            i++;
        }
        chars[idx++] = curr_char;
        if (count > 1) {
            string cnt_str = to_string(count);
            for (char c : cnt_str) {
                chars[idx++] = c;
            }
        }

        return idx;
    }
};
