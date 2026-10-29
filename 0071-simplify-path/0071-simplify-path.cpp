class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string token;
        stringstream ss(path);

        while (getline(ss, token, '/')) {
            if (token.empty() || token == ".") continue;

            if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }

        if (stack.empty()) return "/";

        string result;
        for (const string& dir : stack) {
            result += "/" + dir;
        }
        return result;
    }
};