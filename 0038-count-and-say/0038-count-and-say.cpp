class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        for (int i = 2; i <= n; i++) {
            string next = "";
            int j = 0;
            while (j < cur.size()) {
                char c = cur[j];
                int count = 0;
                while (j < cur.size() && cur[j] == c) {
                    count++;
                    j++;
                }
                next += to_string(count);
                next += c;
            }
            cur = next;
        }
        return cur;
    }
};