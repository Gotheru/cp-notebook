#define PROBLEM "https://vjudge.net/problem/Kattis-shortestpath1"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Basics/Dijkstra.h"
//
void Gotheru::solve() {
    int n, m, q, s;
    while (cin >> n >> m >> q >> s, n) {
        Dijkstra<int, true> g;
        g.init(n);
        rep(m) {
            int u, v, w;
            cin >> u >> v >> w;
            g.ae(u, v, w);
        }
        g.gen(s);
        rep(q) {
            int u; cin >> u;
            if (g.dist[u] == numeric_limits<int>::max()) cout << "Impossible\n";
            else cout << g.dist[u] << '\n'; 
        }
        cout << '\n';
    }
}