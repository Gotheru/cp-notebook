#define PROBLEM "https://vjudge.net/problem/Kattis-aqueducts"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Basics/Dijkstra.h"
//
#include "../../content/graphs/Matching/Hungarian.h"
//
void Gotheru::solve() {
    int n, s, t; db q;
    cin >> n >> s >> t >> q;
    V<AR<db, 3>> hills(n);
    F0R(i, n) F0R(j, 3) cin >> hills[i][j];
    auto dist = [&](int i, int j) -> db {
        if (hills[j][2] >= hills[i][2]) return numeric_limits<db>::max();
        db ans = 0;
        F0R(k, 3) ans += (hills[i][k] - hills[j][k]) * (hills[i][k] - hills[j][k]);
        return sqrt(ans);
    };
    vi springs(s), towns(t);
    each(x, springs) cin >> x, --x;
    each(x, towns) cin >> x, --x;
    Dijkstra<db, true> g;
    g.init(n);
    F0R(i, n) F0R(j, n)
        if (dist(i, j) <= q)
            g.ae(i, j, dist(i, j));
    // do s dijktras to assign distances to towns
    V<vd> C(t, vd(s));
    F0R(j, s) {
        g.gen(springs[j]);
        F0R(i, t) C[i][j] = g.dist[towns[i]];
    }
    db ans = hungarian(C).back();
    if (ans == numeric_limits<db>::max()) cout << "IMPOSSIBLE\n";
    else cout << fixed << setprecision(8) << ans << '\n';
}