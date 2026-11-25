#include <bits/stdc++.h>

using namespace std;

constexpr int kMaxN = 3e6 + 7;

int trie[kMaxN][27], fail[kMaxN], cnt[kMaxN], ed[kMaxN], q[kMaxN], total;

void insert(string &s, int idx) {
    int u = 0;
    for (auto c : s) {
        int k = c - 'a';
        if (trie[u][k] == 0) trie[u][k] = ++total;
        u = trie[u][k];
    }
    ed[idx] = u;
}

void build() {
    int head = 0, tail = 0;
    for (int i = 0; i < 26; i++) {
        if (trie[0][i]) {
            int v = trie[0][i];
            q[tail++] = v;
            fail[v] = 0;
        } else trie[0][i] = 0;
    }
    while (head < tail) {
        int u = q[head++];
        for (int i = 0; i < 26; i++) {
            int v = trie[u][i];
            if (v) {
                fail[v] = trie[fail[u]][i];
                q[tail++] = v;
            } else trie[u][i] = trie[fail[u]][i];
        }
    }
}

void query(string &s) {
    int u = 0;
    for (auto c : s) {
        u = trie[u][c - 'a'];
        cnt[u]++;
    }
}

int n;
string ss;

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        insert(s, i + 1);
    }
    build();
    cin >> ss;
    query(ss);
    for (int i = total; i >= 1; i--) {
        int v = q[i - 1];
        cnt[fail[v]] += cnt[v];
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[ed[i]] << "\n";
    }
    return 0;
}