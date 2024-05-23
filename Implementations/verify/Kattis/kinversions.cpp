#define PROBLEM "https://open.kattis.com/problems/kinversions"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/numerical/Polynomials/FFT.h"
//
void Gotheru::solve() {
    using number = mint<998244353, 5>;
    str S; cin >> S;
    int N = sz(S);
    V<number> P1(N), P2(N);
    F0R(i, N)
        if (S[i] == 'A') P1[i] = 1, P2[N - i - 1] = 0;
        else P1[i] = 0, P2[N - i - 1] = 1;
    auto P = mulMod<number, number>(P1, P2);
    FOR(k, 1, N) {
        cout << P[N + k - 1] << '\n';
    }
}