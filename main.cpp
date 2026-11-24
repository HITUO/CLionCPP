#include <bits/stdc++.h>

using namespace std;

constexpr int kMaxN = 3e6 + 7;

int T, n, q;

int trans(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    if ('A' <= c && c <= 'Z') return c - 'A' + 26;
    if ('0' <= c && c <= '9') return c - '0' + 52;
    return -1;
}

struct Trie {
    int idx, son[kMaxN][70], cnt[kMaxN];

    void insert(string &word) {
        int u = 1;
        for (auto c : word) {
            int v = trans(c);
            if (son[u][v] == 0) {
                son[u][v] = ++idx;
                memset(son[idx], 0, sizeof(son[idx]));
                cnt[idx] = 0;
            }
            u = son[u][v];
            cnt[u]++;
        }
    }

    int query(string &word) {
        int u = 1;
        for (auto c : word) {
            int v = trans(c);
            if (son[u][v] == 0) return 0;
            u = son[u][v];
        }
        return cnt[u];
    }
} tree;

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T;
    while (T--) {
        tree.idx = 1;
        memset(tree.son[1], 0, sizeof(tree.son[1]));
        tree.cnt[1] = 0;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            tree.insert(s);
        }
        for (int i = 1; i <= q; i++) {
            string s;
            cin >> s;
            cout << tree.query(s) << '\n';
        }
    }
    return 0;
}