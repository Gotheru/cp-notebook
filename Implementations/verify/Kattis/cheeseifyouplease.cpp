#define PROBLEM "https://vjudge.net/problem/Kattis-cheeseifyouplease"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/numerical/Misc/Simplex.h"
//
void Gotheru::solve() {
    int n, m;
    cin >> n >> m;
    V<vd> A(n, vd(m));
    vd b(n), c(m), x;
    F0R(i, n) cin >> b[i];
    F0R(j, m) {
        F0R(i, n) cin >> A[i][j];
        cin >> c[j];
    }
    cout << fixed << setprecision(2) << LPSolver(A, b, c).solve(x) * db(100) << '\n';
}