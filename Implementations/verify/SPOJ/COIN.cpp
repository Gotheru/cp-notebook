#define PROBLEM "https://vjudge.net/problem/SPOJ-COIN"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/combinatorial/MatroidIsect.h"
//
void Gotheru::solve() {
    int R;
    while (cin >> R, R) {
        vpi E(2 * R);
        each(e, E) cin >> e.f >> e.s;
        vi clr(2 * R);
        F0R(i, sz(clr)) clr[i] = i / 2;
        Gmat M1(10000, E);
        Cmat M2(clr);
        MatroidIsect<Gmat, Cmat> I(M1, M2, 2 * R);
        cout << 2 * sz(I.solve()) << '\n';
    }
}