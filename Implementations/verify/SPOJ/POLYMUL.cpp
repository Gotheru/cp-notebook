#define PROBLEM "https://vjudge.net/problem/SPOJ-POLYMUL"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/numerical/Polynomials/FFT.h"
//
#include "../../content/number-theory/Euclid/CRT.h"
//
using n0 = mint<(119<<23)+1,62>;
using n1 = mint<(5<<25)+1,  62>;

void Gotheru::solve() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vi A(N + 1), B(N + 1);
        each(a, A) cin >> a;
        each(b, B) cin >> b;
        reverse(all(A));
        reverse(all(B));
        V<n0> p1 = mulMod<n0>(A, B);
        V<n1> p2 = mulMod<n1>(A, B);
        R0F(i, sz(p1)) {
            cout << CRT(mp(p1[i].v, p1[i].mod), mp(p2[i].v, p2[i].mod)).f << " \n"[i == 0];
        }
    }
}