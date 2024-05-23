#define PROBLEM "https://vjudge.net/problem/Yosupo-convolution_mod"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/numerical/Polynomials/FFT.h"
//
void Gotheru::solve() {
    int N, M; cin >> N >> M;
    vmi A(N), B(M);
    each(a, A) cin >> a.v;
    each(b, B) cin >> b.v;
    cout << conv_general(A, B) << '\n';
}