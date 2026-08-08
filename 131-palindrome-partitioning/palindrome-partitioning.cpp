class Solution {
public:

    bool isPalindrome(string str, int i, int j) {
        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string s, int i, int size,
               vector<vector<string>>& ans,
               vector<string>& temp) {

        if (i == size) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < size; j++) {

            if (isPalindrome(s, i, j)) {

                temp.push_back(s.substr(i, j - i + 1));

                solve(s, j + 1, size, ans, temp);

                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        int n = s.length();

        solve(s, 0, n, ans, temp);

        return ans;
    }
};