#define PROBLEM "https://vjudge.net/problem/Yosupo-range_affine_range_sum"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/number-theory/Modular_Arithmetic/ModInt.h"
//
#include "../../content/data-structures/1D-range-queries/LazySegTree.h"
//
using modint = mint<998244353,5>;
using T = pair<modint, modint>;
using E = pair<modint, modint>;
T f(T a, T b) {
    return mp(a.f + b.f, a.s + b.s);
}
T g(T a, E b) {
    return mp(a.f * b.f + a.s * b.s, a.s);
}
E h(E a, E b) {
    return mp(a.f * b.f, a.s * b.f + b.s);
}
T ti() { return mp(0, 0); }
E ei() { return mp(1, 0); }

void Gotheru::solve() {
    int N, Q; cin >> N >> Q;
    V<T> a(N);
    each(x, a) cin >> x.f.v, x.s = 1;
    LazySegTree<T, E, f, g, h, ti, ei> st(a);
    rep(Q) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if (tp) {
            cout << st.query(l, r).f.v << '\n';
        } else {
            modint b, c;
            cin >> b.v >> c.v;
            st.update(l, r, mp(b,c));
        }
    }
}