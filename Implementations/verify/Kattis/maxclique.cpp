#define PROBLEM "https://vjudge.net/problem/Kattis-maxclique"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Advanced/MaxClique.h"
//
void Gotheru::solve() {
    int V, E;
    cin >> V >> E;
    vector<bitset<200>> g(200);
    rep(E) {
        int u, v; cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    MaxClique clique;
    cout << sz(clique.solve(g)) << '\n';
}