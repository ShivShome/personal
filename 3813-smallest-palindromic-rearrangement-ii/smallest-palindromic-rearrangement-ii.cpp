class Solution {
public:
    using ll = long long;
    static const int LIM = 1000001;

    vector<int> primes;

    void sieve(int n) {
        vector<bool> vis(n + 1, false);
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                primes.push_back(i);
                for (ll j = 1LL * i * i; j <= n; j += i)
                    vis[j] = true;
            }
        }
    }

    int exponent(int n, int p) {
        int res = 0;
        while (n) {
            n /= p;
            res += n;
        }
        return res;
    }

    ll powerCap(ll a, int e) {
        ll res = 1;
        while (e--) {
            if (res > LIM / a) return LIM;
            res *= a;
        }
        return min<ll>(res, LIM);
    }

    ll countWays(vector<int>& cnt) {
        int tot = 0;
        for (int x : cnt) tot += x;

        ll ans = 1;

        for (int p : primes) {
            if (p > tot) break;
            int e = exponent(tot, p);
            for (int x : cnt)
                e -= exponent(x, p);

            if (e > 0) {
                ll cur = powerCap(p, e);
                if (ans > LIM / cur) return LIM;
                ans *= cur;
                if (ans >= LIM) return LIM;
            }
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26);
        string mid = "";

        int m = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            m += half[i];
            if (freq[i] & 1)
                mid.push_back(char('a' + i));
        }

        sieve(m);

        if (countWays(half) < k) return "";

        string left;

        for (int pos = 0; pos < m; pos++) {
            for (int c = 0; c < 26; c++) {
                if (!half[c]) continue;

                half[c]--;
                ll ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};