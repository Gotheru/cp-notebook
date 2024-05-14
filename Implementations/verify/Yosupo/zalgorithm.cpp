#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Light/Z.h"
//
void Gotheru::solve() {
    cin.tie(0)->sync_with_stdio(0);
    str S; cin >> S;
    cout << z(S) << '\n';
}