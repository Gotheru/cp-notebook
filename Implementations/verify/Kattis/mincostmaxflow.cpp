#define PROBLEM "https://vjudge.net/problem/Kattis-mincostmaxflow"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Flows/MCMF.h"
//
void Gotheru::solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    MCMF mf;
    mf.init(n);
    rep(m) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        mf.ae(u, v, c, w);
    }
    auto ans = mf.calc(s, t);
    cout << ans.f << ' ' << ans.s << '\n';
}