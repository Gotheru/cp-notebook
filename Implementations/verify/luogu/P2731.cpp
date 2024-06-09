#define PROBLEM "https://vjudge.net/problem/洛谷-P2731"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/DFS/EulerPath.h"
//
void Gotheru::solve() {
    int m; cin >> m;
    int n = 0;
    V<vi> g(505);
    vi deg(505);
    rep(m) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        ckmax(n, u);
        ckmax(n, v);
        --u, --v;
        g[u].pb(v);
        ++deg[v], ++deg[u];
    }
    Euler<false> euler; euler.init(n);
    F0R(i, n) {
        sort(all(g[i]));
        each(j, g[i]) euler.ae(i, j);
    }
    int done = 0;
    vpi ans;
    F0R(i, n) if (deg[i] & 1) {
        ans = euler.solve(i);
        done = 1;
        break;
    }
    if (!done) ans = euler.solve();
    each(x, ans) cout << x.f + 1 << '\n';
}