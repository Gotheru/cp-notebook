#define PROBLEM "https://vjudge.net/problem/Kattis-eulerianpath"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/DFS/EulerPath.h"
//
void Gotheru::solve() {
    int n, m;
    while (cin >> n >> m, n) {
        Euler<true> g;
        g.init(n);
        vi in(n), out(n);
        rep(m) {
            int x, y; cin >> x >> y;
            g.ae(x, y);
            ++in[y], ++out[x];
        }
        int done = 0;
        vpi ans;
        F0R(u, n) if (out[u] == in[u] + 1) {
            ans = g.solve(u);
            done = 1;
            break;
        }
        if (!done) ans = g.solve();
        if (!sz(ans)) cout << "Impossible\n";
        else F0R(i, sz(ans)) cout << ans[i].f << " \n"[i == n - 1];
    }
}