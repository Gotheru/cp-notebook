#define PROBLEM "https://vjudge.net/problem/SPOJ-BABY"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Matching/Hungarian.h"
//
void Gotheru::solve() {
    int N;
    while (cin >> N, N) {
        vi v(N), w(N);
        each(x, v) cin >> x;
        each(x, w) cin >> x;
        V<vi> C(N, vi(N));
        F0R(i, N) F0R(j, N) C[i][j] = abs(i - j) + abs(v[i] - w[j]);
        cout << hungarian(C).back() << '\n';
    }
}