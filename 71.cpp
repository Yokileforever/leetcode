class Solution {
public:
    string simplifyPath(string path) {
        int n = (int)path.size();
        if (path[n - 1] != '/') path = path + "/";
        vector<string> ans;
        n = (int)path.size();
        for (int i = 1; i < n; ++i) {
            string tmp;
            if (path[i] != '/') {
                int c = i;
                while (path[c] != '/')  tmp += path[c], c++;
                i = c;
                if (tmp == "..") {
                    if (!ans.empty())   ans.pop_back();
                } else if (tmp == ".") {
                    
                } else {
                    ans.push_back(tmp);
                }
            }
        }
        if (ans.empty())    return "/";
        string x = "/";
        for (int i = 0; i < ans.size(); ++i) {
            x += ans[i];
            if (i != (int)ans.size() - 1) {
                x += "/";
            }
        }
        return x;
    }
};
