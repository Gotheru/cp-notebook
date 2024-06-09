#define PROBLEM "https://vjudge.net/problem/Yosupo-k_shortest_walk"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Advanced/KthWalk.h"
//
void Gotheru::solve() {
    int N, M, s, t, K;
    cin >> N >> M >> s >> t >> K;
    vector<vector<pair<int, int>>> g(N);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w);
    }
    auto ans = kth_shortest_paths<ll>(N, g, s, t, K);
    while (sz(ans) < K) ans.pb(-1);
    each(x, ans) cout << x << '\n';
}