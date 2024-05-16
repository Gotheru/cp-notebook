#define PROBLEM "https://open.kattis.com/problems/trafikverketsplan"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Trees/LCArmq.h"
//
void Gotheru::solve() {
    int N; cin >> N;
    LCA lca; lca.init(N);
    V<vi> G(N), G1(N), G2(N);
    F0R(i, N - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].pb(b);
        G1[a].pb(b);
        G[b].pb(a);
        G2[b].pb(a);
        lca.ae(a, b);
    }
    vi up(N, -1), down(N, -1);
    auto dfs = [&](auto&& self, int u, int p) -> void {
        up[u] = down[u] = u;
        for (int v : G1[u])
            if (v == p)
                up[u] = up[p];
        for (int v : G2[u])
            if (v == p)
                down[u] = down[p];
        for (int v : G[u])
            if (v != p)
                self(self, v, u);
    };
    dfs(dfs,0,-1);
    lca.gen();
    int Q; cin >> Q;
    F0R(i, Q) {
        int a, b; cin >> a >> b; --a, --b;
        cout << (lca.lca(up[a], lca.lca(a, b)) == up[a] && lca.lca(down[b], lca.lca(a, b)) == down[b] ? "ja\n" : "nej\n");
    }
}