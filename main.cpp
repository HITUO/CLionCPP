#include <bits/stdc++.h>

using namespace std;

constexpr int kMaxN = 3e6 + 7, kMaxW = 30;

struct Tire {
    int idx;
    vector<array<int, 2>> son;
    vector<int> val;

    Tire(int _n) : idx(1), son(_n * 32 + 7), val(_n * 32 + 7) {}

    void insert(int x) {
        int u = 0;
        for (int i = kMaxW; i >= 0; i--) {
            int b = (x >> i) & 1, &v = son[u][b];
            if (!v) v = idx++;
            u = v;
        }
        val[u] = x;
    }

    int query(int x) {
        int u = 0;
        for (int i = kMaxW; i >= 0; i--) {
            int b = (x >> i) & 1;
            u = son[u][b ^ 1] ? son[u][b ^ 1] : son[u][b];
        }
        return val[u];
    }
};

int n;

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    Tire tree(n + 1);
    tree.insert(0);
    int ans = -1, sx = 0, x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sx ^= x;
        ans = max(ans, sx ^ tree.query(sx));
        tree.insert(sx);
    }
    cout << ans << '\n';
    return 0;
}