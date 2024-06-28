#define PROBLEM "https://vjudge.net/problem/Yosupo-vertex_add_path_sum"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Trees/HLD.h"
//
using T = pair<ll,ll>;
using E = ll;
T f(T a, T b) { return mp(a.f + b.f, a.s + b.s); }
T g(T a, E b) { return mp(a.f + b * a.s, a.s); }
E h(E a, E b) { return a + b; }
T ti() { return mp(0, 0); }
E ei() { return 0; }

void Gotheru::solve() {
    int N, Q;
    cin >> N >> Q;
    vl a(N);
    each(x, a) cin >> x;
    vpi eds(N - 1);
    each(e, eds) cin >> e.f >> e.s;
    HLD<T, E, f, g, h, ti, ei, false> hld(N);
    each(e, eds) hld.ae(e.f, e.s);
    hld.init();
    F0R(i,N) hld.set(i,mp(a[i],1));
    rep(Q) {
        int tp; cin >> tp;
        if (!tp) {
            int p; ll x;
            cin >> p >> x;
            hld.modifyPath(p,p,x);
        } else {
            int u, v;
            cin >> u >> v;
            cout << hld.queryPath(u, v).f << '\n';
        }
    }
}