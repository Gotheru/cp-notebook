#define PROBLEM "https://vjudge.net/problem/Yosupo-persistent_unionfind"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/DSU/DSUrb.h"
//
void Gotheru::solve() {
    int N, Q; cin >> N >> Q;
    vi t(Q + 1), u(Q + 1), v(Q + 1), ans(Q + 1);
    V<vi> g(Q + 1);
    F0R(i, Q) {
        int k;
        cin >> t[i + 1] >> k >> u[i + 1] >> v[i + 1];
        ++k;
        g[k].pb(i+1);
    }
    DSUrb uf; uf.init(N);
    auto dfs = [&](int cur, auto&& self) -> void {
        if (!t[cur]) uf.unite(u[cur], v[cur]);
        else ans[cur] = uf.sameSet(u[cur], v[cur]);
        each(nxt, g[cur]) self(nxt, self);
        if (!t[cur]) uf.rollback();
    };
    dfs(0, dfs);
    FOR(i, 1, Q + 1) if (t[i]) cout << ans[i] << '\n';
}