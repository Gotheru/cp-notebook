#define PROBLEM "https://vjudge.net/problem/DMOJ-dmopc19c3p6"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/combinatorial/MatroidPart.h"
//
void Gotheru::solve() {
    int N, M; cin >> N >> M;
    vpi E(M);
    each(e, E) cin >> e.f >> e.s;
    MatroidPart<Gmat> partition(M, 3, 3 * (N - 1), Gmat(E));
    int cnt = 0;
    each(x, partition.iset)
        if (x >= 0)
            ++cnt;
    if (cnt < 3 * (N -1))
        cout << -1;
    else
        each(x, partition.iset) cout << x + 1;
    cout << '\n';
}