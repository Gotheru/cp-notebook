#define PROBLEM "https://vjudge.net/problem/CodeForces-632E"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/numerical/Polynomials/FFT.h"
//
using number = mint<998244353, 5>;
using vn = V<number>;

vn binpow(vn p, ll k) {
    vn ans(sz(p));
    ans[0] = 1;
    for(;k;k>>=1) {
        if (k & 1) ans = mulMod<number>(ans, p);
        p = mulMod<number>(p, p);
        each(x, ans) if (x != 0) x = 1;
        each(x, p) if (x != 0) x = 1;
    }
    return ans;
}

void Gotheru::solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    each(ai, a) cin >> ai;
    int mx = *max_element(all(a));
    vn poly(mx + 1);
    each(x, a) poly[x] = 1;
    poly = binpow(poly, k);
    F0R(i, sz(poly)) if (poly[i] != 0) cout << i << ' ';
    cout << '\n';
}