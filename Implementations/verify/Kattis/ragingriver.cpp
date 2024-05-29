#define PROBLEM "https://vjudge.net/problem/Kattis-ragingriver"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Flows/MCMF.h"
//
void Gotheru::solve() {
    int P, R, L; cin >> P >> R >> L;
    MCMF mf;
    R += 3;
    mf.init(R);
    mf.ae(R - 1, 0, P, 0); // restrict max flow to P
    rep(L) {
        int E1, E2; cin >> E1 >> E2;
        E1 += 2; E2 += 2;
        mf.ae(E1, E2, 1, 1);
        mf.ae(E2, E1, 1, 1);
    }
    auto ans = mf.calc(R - 1, 1);
    if (ans.f < P) cout << P - ans.f << " people left behind\n";
    else cout << ans.s << '\n';
}