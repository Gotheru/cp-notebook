#define PROBLEM "https://vjudge.net/problem/Yosupo-convolution_mod"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/numerical/Polynomials/FFT.h"
//
void Gotheru::solve() {
    using number = mint<998244353, 5>;
    int N, M; cin >> N >> M;
    V<number> A(N), B(M);
    each(a, A) cin >> a.v;
    each(b, B) cin >> b.v;
    cout << mulMod<number, number>(A, B) << '\n';
}