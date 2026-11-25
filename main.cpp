#include <bits/stdc++.h>

using namespace std;

constexpr int kMaxN = 3e6 + 7;

struct Trie {
    int idx, son[kMaxN][3], cnt[kMaxN], is_end[kMaxN];

    void insert(vector<int>& word) {
        int u = 1;
        for (int i : word) {
            cnt[u]++;
            if (son[u][i] == 0) {
                son[u][i] = ++idx;
            }
            u = son[u][i];
        }
        is_end[u]++;
    }

    int query(vector<int>& word) {
        int u = 1, ret = 0;
        for (int i : word) {
            if (son[u][i]) {
                u = son[u][i];
                if (is_end[u]) {
                    ret += is_end[u];
                }
            } else return ret;
        }
        // if (is_end[u]) {
        //     ret += is_end[u];
        // }
        ret += cnt[u];
        return ret;
    }
} root;

int m, n;

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> m >> n;
    root.idx = 1;
    memset(root.son, 0, sizeof(root.son));
    memset(root.is_end, 0, sizeof(root.is_end));
    memset(root.cnt, 0, sizeof(root.cnt));
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        vector<int> word;
        for (int j = 1; j <= x; j++) {
            int xx;
            cin >> xx;
            word.push_back(xx);
        }
        root.insert(word);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vector<int> word;
        for (int j = 1; j <= x; j++) {
            int xx;
            cin >> xx;
            word.push_back(xx);
        }
        cout << root.query(word) << endl;
    }
    return 0;
}