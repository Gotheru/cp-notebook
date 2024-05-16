#define PROBLEM "https://vjudge.net/problem/AtCoder-abc258_g"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/data-structures/STL/Bset.h"
//
void Gotheru::solve() {
    int N; cin >> N;
    vector<tr2::dynamic_bitset<>> adj(N);
    F0R(i, N) {
        adj[i].rsz(N);
        F0R(j, N) {
            char c; cin >> c;
            adj[i][j] = c-'0';
        }
    }
    ll ans = 0;
    F0R(i, N) FOR(j, i+1, N) if (adj[i][j]) ans += (adj[i] & adj[j]).count();
    cout << ans / 3 << '\n';
}