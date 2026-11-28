#include <bits/stdc++.h>

using namespace std;

#define int long long

constexpr int kMaxN = 3e6 + 7, kMaxW = 30;

int c, T, a, b;

int calculate(int x) {
    return (a + x) / __gcd(b + x, a - b) * (b + x);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> c >> T;
    while (T--) {
        cin >> a >> b;
        if (a == b) {
            cout << a << endl;
            continue;
        }
        int ans = LLONG_MAX;
        if (a < b) {
            swap(a, b);
        }
        int t = a - b;
        for (int i = 1; i * i <= t; i++) {
            int left = t / i;
            int n1 = (i - a % i) % i, n2 = (left - a % left) % left;
            ans = min(ans, calculate(n1));
            ans = min(ans, calculate(n2));
        }
        cout << ans << endl;
    }
    return 0;
}// CopyCodeForces abbr.CCF