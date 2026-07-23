class Solution {
public:
    string decodeString(string s) {
        stack<int> cnt;
        stack<string> st;

        string ans = "";
        int i = 0, n = s.size();

        while (i < n) {
            if (isdigit(s[i])) {
                int temp = 0;
                while (i < n && isdigit(s[i])) {
                    temp = temp * 10 + (s[i] - '0');
                    i++;
                }
                cnt.push(temp);
            }
            else if (s[i] == '[') {
                st.push(ans);
                ans = "";
                i++;
            }
            else if (s[i] == ']') {
                string cur = ans;
                ans = st.top();
                st.pop();

                int k = cnt.top();
                cnt.pop();

                while (k--) ans += cur;
                i++;
            }
            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};